import { Outlet } from "react-router-dom";
import Input from "./Input";

function AppLayout() {
  return (
    <div>
      <div className="bg-midnight h-screen w-screen flex flex-col">
        <div className="mx-auto pt-10 ">
          <Input />
        </div>
        <Outlet />
      </div>
    </div>
  );
}

export default AppLayout;
