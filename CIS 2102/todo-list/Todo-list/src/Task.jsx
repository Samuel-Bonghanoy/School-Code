function Task({ entry, setTaskList }) {
  return (
    <li className="flex flex-col  text-slate-800 bg-slate-300 my-2 px-3 py-3 w-full hover:bg-slate-400 hover:scale-[1.03] hover:shadow-slate-400 transition-all rounded-md">
      <div className="flex items-center">
        <input
          onChange={() =>
            setTaskList((li) => li.filter((task) => task !== entry))
          }
          type="checkbox"
          className="w-4 h-4 text-blue-600 bg-gray-100 border-gray-300 rounded focus:ring-blue-500 dark:focus:ring-blue-600 dark:ring-offset-gray-800 focus:ring-2 dark:bg-gray-700 dark:border-gray-600"
        />
        <p className="ml-2 font-semibold">{entry}</p>
      </div>
      <p className="text-sm text-green-800">Due Today</p>
    </li>
  );
}

export default Task;
