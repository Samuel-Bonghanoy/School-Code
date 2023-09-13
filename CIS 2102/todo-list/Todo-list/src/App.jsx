import List from "./List";
import styles from "./App.module.css";
import { useState, useEffect, useRef } from "react";

function App() {
  const [taskList, setTaskList] = useState(["do this shit", "do that shit"]);
  let entry = "";

  const input = useRef(null);

  useEffect(() => {
    function callback(e) {
      if (e.code === "Enter") {
        if (entry) setTaskList((list) => [...list, entry]);
        input.current.value = "";
      }
    }

    document.addEventListener("keydown", callback);

    return function () {
      document.removeEventListener("keydown", callback);
    };
  }, [setTaskList, entry]);

  return (
    <div className={styles.container}>
      <div className={styles.input}>
        <input
          ref={input}
          onChange={(e) => {
            entry = e.target.value;
            console.log(entry);
          }}
          placeholder="Input Task"
        ></input>
        <button
          onClick={() => {
            if (entry) setTaskList((list) => [...list, entry]);
            input.value = "";
          }}
        >
          Submit
        </button>
      </div>
      <List entries={taskList} setTaskList={setTaskList} />
    </div>
  );
}

export default App;
