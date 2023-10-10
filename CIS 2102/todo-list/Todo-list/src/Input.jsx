import { useState } from "react";
import { useList } from "./contexts/listContext";
import { FiPlusCircle } from "react-icons/fi";
import DatePicker from "react-datepicker";
import "react-datepicker/dist/react-datepicker.css";

function Input() {
  const { setList } = useList();
  const [entry, setEntry] = useState({ body: "", date: null });
  const [add, setAdd] = useState(false);
  const [mouseOver, setMouseOver] = useState(false);
  const [dueDate, setDueDate] = useState(null);

  return (
    <div className="flex items-center gap-2 justify-start ">
      {add ? (
        <div className="flex gap-5">
          <input
            className="w-96 py-2 px-3 active:border-none focus:border-none rounded-md"
            onChange={(e) => {
              setEntry(e.target.value);
            }}
            placeholder="Input Task"
          ></input>
          <DatePicker
            selected={dueDate}
            dateFormat={"dd/MM/yyyy"}
            onChange={(date) => setDueDate(date)}
            className="py-2 px-3 w-64 rounded-md"
          />
        </div>
      ) : (
        <h2 className="text-gray-100 text-xl">Add a task</h2>
      )}
      {add ? (
        <button
          className="py-2 px-2 h-9 "
          onClick={() => {
            if (entry) setList((list) => [...list, entry]);
            setEntry("");
            setAdd(false);
          }}
        >
          <FiPlusCircle
            size="1.3rem"
            color={mouseOver ? "#84cc16" : "white"}
            onMouseOver={() => setMouseOver(true)}
            onMouseOut={() => setMouseOver(false)}
          />
        </button>
      ) : (
        <button
          className=" py-2 px-2 h-9"
          onClick={() => {
            setAdd(true);
          }}
        >
          <FiPlusCircle
            size="1.2rem"
            color={mouseOver ? "#84cc16" : "white"}
            onMouseOver={() => setMouseOver(true)}
            onMouseOut={() => setMouseOver(false)}
          />
        </button>
      )}
    </div>
  );
}

export default Input;
