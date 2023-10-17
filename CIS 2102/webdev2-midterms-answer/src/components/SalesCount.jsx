import { useBuses } from "../contexts/BusContext"
import { usePassengers } from "../contexts/PassengerContext"

function SalesCount() {
  const { bus1Passengers, bus2Passengers, bus3Passengers} = useBuses()

  const salesPriceAfterBus1 = bus1Passengers.reduce((acc, cur) => {
    return acc + cur.destination.price
  }, 0)

  const salesPriceAfterBus2 = bus2Passengers.reduce((acc, cur) => {
    return acc + cur.destination.price
  }, salesPriceAfterBus1)

  const totalPrice= bus3Passengers.reduce((acc, cur) => {
    return acc + cur.destination.price
  }, salesPriceAfterBus2)

  return (
    <>
        <div>
            <h1 className='text-center text-3xl bg-teal-500 py-2 font-bold'>
                Ticket Sales: {totalPrice} PHP
            </h1>
        </div>
    </>
  )
}

export default SalesCount
