import List from "./List";
import styles from "./App.module.css";
import { useState } from "react";

function App() {
  const [taskList, setTaskList] = useState(["do this shit", "do that shit"]);
  let entry = "";
  return (
    <div className={styles.container}>
      <div className={styles.input}>
        <input
          onChange={(e) => {
            entry = e.target.value;
            console.log(entry);
          }}
          placeholder="Input Task"
        ></input>
        <button
          onClick={() => {
            if (entry) setTaskList((list) => [...list, entry]);
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
