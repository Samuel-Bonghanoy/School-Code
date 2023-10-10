import Input from "./Input";
import Task from "./Task";
import { useList } from "./contexts/listContext";

function List() {
  const { list, setList } = useList();

  return (
    <>
      <ul className="">
        {list.map((entry, i) => (
          <Task entry={entry} key={i} setTaskList={setList} identifier={i} />
        ))}
      </ul>
      <Input />
    </>
  );
}

export default List;
