import { createContext, useState, useContext } from "react";

const ListContext = createContext();

function ListProvider({ children }) {
  const [list, setList] = useState(["do this", "do that"]);

  return (
    <ListContext.Provider
      value={{
        list,
        setList,
      }}
    >
      {children}
    </ListContext.Provider>
  );
}

function useList() {
  const context = useContext(ListContext);
  if (context === undefined)
    throw new Error("ListContext used outside of the provider");
  return context;
}

export { ListProvider, useList };
