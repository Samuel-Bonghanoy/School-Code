import { RouterProvider, createBrowserRouter } from "react-router-dom";
import List from "./List";
import AppLayout from "./AppLayout";
import { ListProvider } from "./contexts/listContext";

const router = createBrowserRouter([
  {
    element: <AppLayout />,
    children: [
      {
        path: "/",
        element: <List />,
      },
      {
        path: "/task",
        element: <AppLayout />,
      },
    ],
  },
]);

function App() {
  return (
    <ListProvider>
      <RouterProvider router={router} />
    </ListProvider>
  );
}

export default App;
