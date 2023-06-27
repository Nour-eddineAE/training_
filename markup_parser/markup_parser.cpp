#include <iostream>
#include <sstream>
#include <vector>
#include <map>
using namespace std;

struct Tag
{
  std::string name;
  std::map<std::string, std::string> attributes;
  std::vector<Tag> children;
};

// Parse a single tag from the given input stream
Tag parseTag(std::istringstream &stream, string line_)
{
  Tag tag;
  string current_line = line_;

  // ? Parse tag name
  // 1) get index of the first element != <
  size_t start = current_line.find_first_not_of(" \t\n\r<");

  // 2) get index of last element before: ' ', starting from: start
  size_t end = current_line.find(' ', start);
  if (end == std::string::npos)
  {
    // * If no attributes are present, the tag name extends to the end of the line
    end = current_line.find('>', start);
  }

  // 3) tag name will be the string between these 2 positions
  tag.name = current_line.substr(start, end - start);

  // * if it's a closing tag then return immediately
  if (current_line.find("</" + tag.name + ">") != std::string::npos)
  {
    return tag;
  }

  // ? Parse tag attributes

  // 1) find the position of the first = operator starting from position: end
  size_t pos = current_line.find('=', end);

  // * while we have equal operators
  while (pos != std::string::npos)
  {
    // 2) find the last occurence of the given character when we search backaward starting
    //  from the given position, in other words: the position of the first space after the attribute
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
    // * +1 in substr to count the last element if we do a substraction
    std::string attribute = current_line.substr(attrStart, attrEnd - attrStart + 1);

    size_t valueStart = current_line.find('\"', pos) + 1;
    size_t valueEnd = current_line.find('\"', valueStart);
    std::string value = current_line.substr(valueStart, valueEnd - valueStart);

    tag.attributes[attribute] = value;
    pos = current_line.find('=', valueEnd);
  }

  // ? Parse tag children recursively

  std::string closingTag = "</" + tag.name + ">";

  while (std::getline(stream, current_line))
  {
    tag.children.push_back(parseTag(stream, current_line));
  }
  return tag;
}

// ? Find the value of the specified query in the given tag
std::string findValue(const Tag &tag, const std::string &query)
{
  // * get attribute and serie of tags
  size_t delimiterPos = query.find('~');

  std::string tagName = query.substr(0, delimiterPos);

  std::string attribute = query.substr(delimiterPos + 1);

  size_t dotPos = tagName.find('.');
  // * if single tag i.e no dots
  if (dotPos == std::string::npos)
  {
    if (tagName == tag.name && tag.attributes.count(attribute) > 0)
    {
      return tag.attributes.at(attribute);
    }
  }
  else
  {
    // * Nested tag query
    std::string currentTagName = tagName.substr(0, dotPos);

    std::string remainingTags = tagName.substr(dotPos + 1);

    if (currentTagName == tag.name)
    {
      for (const Tag &child : tag.children)
      {
        std::string result = findValue(child, remainingTags + "~" + attribute);
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
  std::cin >> numTags >> numQueries;
  // Ignore the newline character
  std::cin.ignore();

  std::string markup;
  std::string line;

  // groupe tags in one string, to build the stream
  for (int i = 0; i < numTags; i++)
  {
    std::getline(std::cin, line);
    markup += line + '\n';
  }

  // store queries in a vector
  std::vector<std::string> queries;
  for (int i = 0; i < numQueries; i++)
  {
    std::getline(std::cin, line);
    queries.push_back(line);
  }

  // get the root tag [parse as a tree]
  std::istringstream stream(markup);
  string first_line;
  getline(stream, first_line);

  Tag rootTag = parseTag(stream, first_line);

  // treating queries
  std::vector<std::string> results;
  for (const std::string &query : queries)
  {
    std::string value = findValue(rootTag, query);
    results.push_back(value);
  }

  // Print the results
  for (const std::string &result : results)
  {
    std::cout << result << std::endl;
  }
  return 0;
}