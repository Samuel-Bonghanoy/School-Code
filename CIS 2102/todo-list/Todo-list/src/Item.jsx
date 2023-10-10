import { useParams } from "react-router-dom";
import { useList } from "./contexts/listContext";

function Item() {
  const { id } = useParams();
  const { list } = useList;

  return (
    <div className="flexflex-col">
      <p className="ml-2 font-semibold text-[1.1rem]">{list[id]}</p>
      <p className="ml-2 text-[0.75rem] text-green-800 font-thin">due Monday</p>
    </div>
  );
}

export default Item;
