import { useNavigate, useParams } from "react-router-dom";
import { useList } from "./contexts/listContext";

function Item() {
  const { id } = useParams();
  const { list } = useList();
  // console.log(list, id, flag);
  const navigate = useNavigate();

  return (
    <>
      <div className="flex flex-col text-slate-800 bg-slate-300 my-2 px-3 py-3 w-full rounded-md">
        <p className="ml-2 font-semibold text-[1.1rem]">{list[id]}</p>
        <p className="ml-2 text-[0.75rem] text-green-800 font-thin">
          due Monday
        </p>
      </div>
      <button
        className="bg-red-300  hover:bg-red-500 hover:scale-[1.01] hover:shadow-slate-400 transition-all rounded-md"
        onClick={() => {
          navigate(-1);
        }}
      >
        Back
      </button>
    </>
  );
}

export default Item;
