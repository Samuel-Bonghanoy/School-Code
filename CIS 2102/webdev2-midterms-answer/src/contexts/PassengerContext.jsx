import { createContext, useState, useEffect, useContext } from "react";

const PassengerContext = createContext();

function PassengerProvider({ children }) {
  const [passengers, setPassengers] = useState([]);
  const [destinations, setDestinations] = useState([]);
  const [isLoading, setIsLoading] = useState(true);

  useEffect(() => {
    async function fetchItems() {
      try {
        const passengers = await fetch(
          "https://my-json-server.typicode.com/troy1129/jsonplaceholder/passengers"
        );
        const passengerData = await passengers.json();
        setPassengers(passengerData);

        const destinations = await fetch(
          "https://my-json-server.typicode.com/troy1129/jsonplaceholder/destinations"
        );
        const destinationData = await destinations.json();
        setDestinations(destinationData);

        setIsLoading(false);
      } catch (error) {
        console.error("Error fetching data: ", error);
        setIsLoading(false);
      }
    }

    fetchItems();
  }, []);

  //   console.log(passengers, destinations)
  return (
    <PassengerContext.Provider
      value={{ isLoading, passengers, setPassengers, destinations }}
    >
      {children}
    </PassengerContext.Provider>
  );
}

function usePassengers() {
  const context = useContext(PassengerContext);
  if (context === undefined)
    throw new Error("PassengerContext used outside of the provider");
  return context;
}

export { PassengerProvider, usePassengers };
