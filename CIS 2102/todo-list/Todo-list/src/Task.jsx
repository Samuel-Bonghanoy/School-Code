import styles from "./Task.module.css";
function Task({ entry }) {
  return (
    <li>
      <input type="checkbox" />
      <p>{entry}</p>
    </li>
  );
}

export default Task;
