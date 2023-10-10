import { Outlet } from "react-router-dom";
import Input from "./Input";

function AppLayout() {
  return (
    <div>
      <div className="bg-midnight h-screen w-screen flex flex-col font-sans">
        <Input />
        <Outlet />
      </div>
    </div>
  );
}

export default AppLayout;
