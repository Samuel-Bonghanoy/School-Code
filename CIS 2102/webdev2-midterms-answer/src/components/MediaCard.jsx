// import * as React from 'react';
import Card from "@mui/material/Card";
// import CardActions from '@mui/material/CardActions';
import CardContent from "@mui/material/CardContent";
import CardMedia from "@mui/material/CardMedia";
import Button from "@mui/material/Button";
import Typography from "@mui/material/Typography";
import gigaChad from "../assets/gigachadd.jpg";
import { usePassengers } from "../contexts/PassengerContext";
import { useBuses } from "../contexts/BusContext";
// import { Button } from '@mui/material';S

export default function MediaCard(props) {
  const { passenger } = props;
  const { setPassengers, destinations } = usePassengers();
  const { setBus1Passengers, setBus2Passengers, setBus3Passengers } =
    useBuses();

  function handleClick(d) {
    if (d.destination === "Cebu" || d.destination === "Mandaue") {
      setBus1Passengers((p) => [...p, { ...passenger, destination: d }]);
    }

    if (d.destination === "Lilo-an" || d.destination === "Lapu-Lapu") {
      setBus2Passengers((p) => [...p, { ...passenger, destination: d }]);
    }

    if (d.destination === "Consolacion" || d.destination === "Talisay") {
      setBus3Passengers((p) => [...p, { ...passenger, destination: d }]);
    }

    setPassengers((p) => p.filter((pass) => pass != passenger));
  }

  return (
    <Card
      sx={{
        maxWidth: 445,
        width: 250,
        ":hover": {
          boxShadow: 20,
        },
      }}
    >
      <CardMedia sx={{ height: 180 }} image={gigaChad} title="Person" />
      <CardContent className="flex flex-col justify0-center items-center gap-3">
        <Typography gutterBottom variant="h5" component="div">
          {passenger.name}
        </Typography>
        <Typography variant="body2" color="text.secondary">
          ID: {passenger.id}
        </Typography>
        <Typography variant="body2" color="text.secondary">
          No Destination
        </Typography>
        <div className="flex flex-wrap justify-center gap-1">
          {destinations.map((d) => (
            <Button
              onClick={() => handleClick(d)}
              variant="contained"
              key={d.id}
            >
              {d.destination}
            </Button>
          ))}
        </div>
      </CardContent>
    </Card>
  );
}
