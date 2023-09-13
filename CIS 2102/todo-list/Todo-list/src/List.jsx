import Task from "./Task";

function List({ entries, setTaskList }) {
  return (
    <ul>
      {entries.map((entry, i) => (
        <Task entry={entry} key={i} setTaskList={setTaskList} />
      ))}
    </ul>
  );
}

export default List;
