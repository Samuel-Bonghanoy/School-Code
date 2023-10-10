import { useState } from "react";
import { useList } from "./contexts/listContext";

function Input() {
  const { setList } = useList();
  const [entry, setEntry] = useState("");

  return (
    <>
      <input
        className="w-96 py-2 px-2 active:border-none focus:border-none"
        onChange={(e) => {
          setEntry(e.target.value);
        }}
        placeholder="Input Task"
      ></input>
      <button
        className="bg-green-500 py-2 px-2"
        onClick={() => {
          if (entry) setList((list) => [...list, entry]);
          setEntry("");
        }}
      >
        Submit
      </button>
    </>
  );
}

export default Input;
