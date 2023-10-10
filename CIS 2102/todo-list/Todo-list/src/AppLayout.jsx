import { Outlet } from "react-router-dom";
import Input from "./Input";

function AppLayout() {
  return (
    <div className="w-screen h-screen bg-midnight">
      <div className="bg-midnight w-6/12 flex flex-col font-sans mx-auto pt-10 ">
        <Outlet />
        <Input />
      </div>
    </div>
  );
}

export default AppLayout;
