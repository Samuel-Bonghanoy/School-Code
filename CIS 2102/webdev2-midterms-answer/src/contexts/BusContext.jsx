
import { createContext, useState, useContext } from "react";

const BusContext = createContext();

function BusProvider({ children }) {
  const [bus1Passengers, setBus1Passengers] = useState([]);
  const [bus2Passengers, setBus2Passengers] = useState([]);
  const [bus3Passengers, setBus3Passengers] = useState([]);

  return (
    <BusContext.Provider value={{ bus1Passengers, bus2Passengers, bus3Passengers, setBus1Passengers, setBus2Passengers, setBus3Passengers}}>
      {children}
    </BusContext.Provider>
  );
}

function useBuses() {
  const context = useContext(BusContext);
  if (context === undefined)
    throw new Error("BusContext used outside of the provider");
  return context;
}

export { BusProvider, useBuses};
