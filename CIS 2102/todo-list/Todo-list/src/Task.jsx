import { useState } from "react";
import { HiCheckCircle } from "react-icons/hi";
import { Link } from "react-router-dom";

function Task({ entry, setTaskList, identifier }) {
  const [mouseOver, setMouseOver] = useState(false);

  return (
    <Link to={`/tasks/${identifier}`}>
      <li className="flex   text-slate-800 bg-slate-300 my-2 px-3 py-3 w-full hover:bg-slate-400 hover:scale-[1.03] hover:shadow-slate-400 transition-all rounded-md">
        <button
          onClick={() =>
            setTaskList((li) => li.filter((task) => task !== entry))
          }
          type="checkbox"
          // className="h-9 rounded-full border-2 border-green-900 focus:ring-2 focus:ring-gray-600"
        >
          <HiCheckCircle
            size="1.5rem"
            color={mouseOver ? "#16a34a" : "black"}
            onMouseOver={() => setMouseOver(true)}
            onMouseOut={() => setMouseOver(false)}
          />
        </button>
        <div className="flexflex-col">
          <p className="ml-2 font-semibold text-[1.1rem]">{entry}</p>
          <p className="ml-2 text-[0.75rem] text-green-800 font-thin">
            due Monday
          </p>
        </div>
      </li>
    </Link>
  );
}

export default Task;
