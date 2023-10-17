import Form from "./components/Form";
// import MediaCard from './components/MediaCard'
import SalesCount from "./components/SalesCount";
import PassengerList from "./components/PassengersList";
import { PassengerProvider } from "./contexts/PassengerContext";
import { BusProvider } from "./contexts/BusContext";
import BusList from "./components/BusList";
import ResponsiveAppBar from "./components/AppBar";

function App() {
  return (
    <PassengerProvider>
      <BusProvider>
        <ResponsiveAppBar />
        <SalesCount />
        <Form />
        <PassengerList />
        <BusList />
      </BusProvider>
    </PassengerProvider>
  );
}

export default App;
