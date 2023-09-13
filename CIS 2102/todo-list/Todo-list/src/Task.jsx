import styles from "./Task.module.css";
function Task({ entry, setTaskList }) {
  return (
    <li>
      <input
        onChange={() =>
          setTaskList((li) => li.filter((task) => task !== entry))
        }
        type="checkbox"
      />
      <p>{entry}</p>
    </li>
  );
}

export default Task;
