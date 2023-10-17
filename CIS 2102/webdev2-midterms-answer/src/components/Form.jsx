import { Button, TextField } from "@mui/material";
import { useState } from "react";
import { usePassengers } from "../contexts/PassengerContext";
import { ToastContainer, toast } from "react-toastify";
import "react-toastify/dist/ReactToastify.css";

function Form() {
  const { passengers, setPassengers } = usePassengers();
  const [name, setName] = useState("");
  const [id, setID] = useState(null);
  const idArr = passengers.map((p) => p.id);

  function handleSubmit() {
    if (!name || !id) {
      toast.error("Please fill in both inputs!", {
        position: "top-center",
        autoClose: 3000,
        hideProgressBar: false,
        closeOnClick: true,
        pauseOnHover: true,
        draggable: true,
        progress: undefined,
        theme: "colored",
      });
      return;
    }

    if (idArr.includes(id)) {
      toast.error("Person with that ID already exists!", {
        position: "top-center",
        autoClose: 3000,
        hideProgressBar: false,
        closeOnClick: true,
        pauseOnHover: true,
        draggable: true,
        progress: undefined,
        theme: "colored",
      });
      return;
    }

    setPassengers((p) => [...p, { name, id, destination: "" }]);

    toast.success("Successfully added a passenger!", {
      position: "top-center",
      autoClose: 3000,
      hideProgressBar: false,
      closeOnClick: true,
      pauseOnHover: true,
      draggable: true,
      progress: undefined,
      theme: "colored",
    });
  }

  return (
    <div className="flex flex-col w-screen items-center gap-5 my-5">
      <TextField
        required
        variant="filled"
        className="w-[40rem]"
        onChange={(e) => setName(e.target.value)}
        id="outlined-basic"
        label="Enter your name"
      />
      <TextField
        className="mb-3 w-[40rem]"
        required
        onChange={(e) => setID(Number(e.target.value))}
        id="outlined-basic"
        label="Enter your ticket ID"
        variant="outlined"
      />
      <Button onClick={handleSubmit} size="large" variant="contained">
        Add Passenger
      </Button>
      <ToastContainer />
    </div>
  );
}

export default Form;
