import Task from "./Task";

function List({ entries }) {
  return (
    <ul>
      {entries.map((entry, i) => (
        <Task entry={entry} key={i} />
      ))}
    </ul>
  );
}

export default List;
