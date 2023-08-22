class EventEmitter {
    event_queue_map = {};

    subscribe(event, cb) {
        if (this.event_queue_map[event]) this.event_queue_map[event].push(cb);
        else this.event_queue_map[event] = [cb];

        return {
            unsubscribe: () => {
                const cb_index = this.event_queue_map[event].indexOf(cb);

                if (cb_index !== -1) {
                    this.event_queue_map[event].splice(cb_index, 1);
                }
            },
        };
    }

    emit(event, args = []) {
        const event_queue = this.event_queue_map[event];
        if (!event_queue || event_queue.length == 0) return [];

        const res = [];

        for (let cb of event_queue) {
            res.push(cb(...args));
        }

        return res;
    }
}

const emitter = new EventEmitter();
// Subscribe to the onClick event with onClickCallback
function onClickCallback() {
    return 99;
}
emitter.subscribe("onClick", onClickCallback);
const sub = emitter.subscribe("onClick", onClickCallback);
console.log(emitter.emit("onClick")); // [99]
console.log(sub.unsubscribe()); // undefined
console.log(emitter.emit("onClick")); // []
