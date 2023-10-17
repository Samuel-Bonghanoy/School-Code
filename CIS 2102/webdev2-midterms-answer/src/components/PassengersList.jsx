
import { usePassengers } from "../contexts/PassengerContext";
import MediaCard from "./MediaCard"

function PassengersList() {
    const { passengers} = usePassengers();

    return <div className="flex gap-3 bg-gray-200 py-10 w-screen items-center justify-center">
        {passengers.map((p) => <MediaCard passenger={p} key={p.id}/>)}
        {!passengers.length && <p className="font-bold text-2xl">No passengers left to queue</p>}    
    </div>
}

export default PassengersList;