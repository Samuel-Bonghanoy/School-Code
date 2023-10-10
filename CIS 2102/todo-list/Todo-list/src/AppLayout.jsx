import { Outlet } from "react-router-dom";
import Input from "./Input";

function AppLayout() {
  return (
    <div className="w-screen bg-midnight">
      <div className="bg-midnight h-screen w-fit flex flex-col font-sans mx-auto ">
        <Input />
        <Outlet />
      </div>
    </div>
  );
}

export default AppLayout;
