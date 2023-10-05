// import { useState } from "react";
import "./App.css";
// import Form from "./Form";
// import ContactList from "./ContactList";

import { createBrowserRouter, RouterProvider } from "react-router-dom";

const router = createBrowserRouter([
  {
    element: <App />,
  },
]);

function App() {
  // const [contacts, setContacts] = useState([]);
  return <RouterProvider router={router}></RouterProvider>;
}

export default App;
