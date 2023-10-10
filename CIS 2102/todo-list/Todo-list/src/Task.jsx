function Task({ entry, setTaskList }) {
  return (
    <li className="flex text-slate-800 bg-slate-300 my-2 px-3 py-3 w-96">
      <input
        onChange={() =>
          setTaskList((li) => li.filter((task) => task !== entry))
        }
        type="checkbox"
      />
      <p className="ml-2">{entry}</p>
    </li>
  );
}

export default Task;
