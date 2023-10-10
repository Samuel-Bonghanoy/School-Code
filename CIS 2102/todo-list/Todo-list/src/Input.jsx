import { useState } from "react";
import { useList } from "./contexts/listContext";
import { FiPlusCircle } from "react-icons/fi";

function Input() {
  const { setList } = useList();
  const [entry, setEntry] = useState("");
  const [add, setAdd] = useState(false);
  const [mouseOver, setMouseOver] = useState(false);

  return (
    <div className="pt-10 flex gap-2 items-center justify-start">
      {add ? (
        <input
          className="w-96 py-2 px-2 active:border-none focus:border-none"
          onChange={(e) => {
            setEntry(e.target.value);
          }}
          placeholder="Input Task"
        ></input>
      ) : (
        <h2 className="text-gray-100 text-2xl">Add a task</h2>
      )}
      <button
        className=" py-2 px-2 h-9"
        onClick={() => {
          if (entry) setList((list) => [...list, entry]);
          setEntry("");
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
    </div>
  );
}

export default Input;
