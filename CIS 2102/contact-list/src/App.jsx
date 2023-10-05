// import { useState } from "react";
import "./App.css";
// import Form from "./Form";
import ContactListView from "./ContactListView";

import { createBrowserRouter, RouterProvider } from "react-router-dom";
import AppLayout from "./AppLayout";

const router = createBrowserRouter([
  {
    path: "/",
    element: <AppLayout />,
  },
  {
    path: "/contacts",
    element: <ContactListView />,
  },
]);

function App() {
  return <RouterProvider router={router}></RouterProvider>;
}

export default App;
