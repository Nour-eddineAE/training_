#include <iostream>
#include <sstream>
#include <vector>
#include <map>
using namespace std;

struct Tag
{
  string name;
  map<string, string> attributes;
  vector<Tag> children;
};

Tag parseTag(istringstream &stream, string line_)
{
  Tag tag;
  string current_line = line_;

  // Parse tag name
  size_t start = current_line.find_first_not_of(" \t\n\r<");
  size_t end = current_line.find(' ', start);
  if (end == string::npos)
  {
    end = current_line.find('>', start);
  }
  tag.name = current_line.substr(start, end - start);

  // Check if it's a closing tag
  if (current_line.find("</" + tag.name + ">") != string::npos)
  {
    return tag;
  }

  // Parse tag attributes
  size_t pos = current_line.find('=', end);
  while (pos != string::npos)
  {
    size_t attrEnd = 0;
    for (int i = pos - 1; i > 0; i--)
    {
      if (current_line[i] != ' ')
      {
        attrEnd = (size_t)i;
        break;
      }
    }
    size_t attrStart = current_line.rfind(' ', attrEnd) + 1;
    string attribute = current_line.substr(attrStart, attrEnd - attrStart + 1);

    size_t valueStart = current_line.find('\"', pos) + 1;
    size_t valueEnd = current_line.find('\"', valueStart);
    string value = current_line.substr(valueStart, valueEnd - valueStart);

    tag.attributes[attribute] = value;
    pos = current_line.find('=', valueEnd);
  }

  // Parse tag children recursively
  string closingTag = "</" + tag.name + ">";
  string childLine;
  while (getline(stream, childLine))
  {
    if (childLine.find(closingTag) != string::npos)
    {
      break;
    }
    tag.children.push_back(parseTag(stream, childLine));
  }

  return tag;
}

// ? Find the value of the specified query in the given tag
string findValue(const Tag &tag, const string &query)
{
  // * get attribute and serie of tags
  size_t delimiterPos = query.find('~');

  string tagName = query.substr(0, delimiterPos);

  string attribute = query.substr(delimiterPos + 1);

  size_t dotPos = tagName.find('.');
  // * if single tag i.e no dots
  if (dotPos == string::npos)
  {
    if (tagName == tag.name && tag.attributes.count(attribute) > 0)
    {
      return tag.attributes.at(attribute);
    }
  }
  else
  {
    // * Nested tag query
    string currentTagName = tagName.substr(0, dotPos);

    string remainingTags = tagName.substr(dotPos + 1);

    if (currentTagName == tag.name)
    {
      for (const Tag &child : tag.children)
      {
        string result = findValue(child, remainingTags + "~" + attribute);
        if (result != "Not Found!")
        {
          return result;
        }
      }
    }
  }

  return "Not Found!";
}

int main()
{
  int numTags, numQueries;
  cin >> numTags >> numQueries;
  // Ignore the newline character
  cin.ignore();

  string markup;
  string line;

  // groupe tags in one string, to build the stream
  for (int i = 0; i < numTags; i++)
  {
    getline(cin, line);
    markup += line + '\n';
  }

  // store queries in a vector
  vector<string> queries;
  for (int i = 0; i < numQueries; i++)
  {
    getline(cin, line);
    queries.push_back(line);
  }

  // get the root tag [parse as a tree]
  istringstream stream(markup);
  string first_line;
  getline(stream, first_line);

  Tag rootTag = parseTag(stream, first_line);

  // treating queries
  vector<string> results;
  for (const string &query : queries)
  {
    string value = findValue(rootTag, query);
    results.push_back(value);
  }

  // Print the results
  for (const string &result : results)
  {
    cout << result << endl;
  }
  return 0;
}