import { useBuses } from "../contexts/BusContext"
import * as React from 'react';
import List from '@mui/material/List';
import ListItem from '@mui/material/ListItem';
import ListItemText from '@mui/material/ListItemText';
import ListItemAvatar from '@mui/material/ListItemAvatar';
import Avatar from '@mui/material/Avatar';
import ImageIcon from '@mui/icons-material/Image';
import WorkIcon from '@mui/icons-material/Work';
import BeachAccessIcon from '@mui/icons-material/BeachAccess';
import gigaChad from "../assets/gigachadd.jpg"
import DirectionsBusIcon from '@mui/icons-material/DirectionsBus';
import { CardMedia } from "@mui/material";

function BusList() {
    const { bus1Passengers, bus2Passengers, bus3Passengers} = useBuses()
 
    return (
        <div className="flex gap-[20rem] justify-center pt-10 bg-cyan-100">
        <div className="flex flex-col items-center justify-start">
            <div className="flex items-center gap-2">
            <DirectionsBusIcon/>
        <h2 className="font-bold text-2xl text-center">Bus 1</h2>
        </div>
        <List alignItems="flex-start" sx={{ width: '100%', maxWidth: 360, bgcolor: '#cffafe' }}>
            {bus1Passengers.map((p) => <ListItem>
            <ListItemAvatar>
              <Avatar>
              <img src={gigaChad} ></img>
              </Avatar>
            </ListItemAvatar>
            <ListItemText primary={`${p.name} - ID# ${p.id}`} secondary={p.destination.destination}  />
            </ListItem>)}
        </List>
        </div>
        <div className="flex flex-col items-center justify-start">
        <div className="flex items-center gap-2">
            <DirectionsBusIcon/>
        <h2 className="font-bold text-2xl text-center justify-start">Bus 2</h2>
        </div>
        <List alignItems="flex-start" sx={{ width: '100%', maxWidth: 360, bgcolor: '#cffafe' }}>
            {bus2Passengers.map((p) => <ListItem>
            <ListItemAvatar>
              <Avatar>
              <img src={gigaChad} ></img>
              </Avatar>
            </ListItemAvatar>
            <ListItemText primary={`${p.name} - ID# ${p.id}`} secondary={p.destination.destination}  />
            </ListItem>)}
        </List>
        </div>
        <div  className="flex flex-col items-center justify-start">
        <div className="flex items-center gap-2">
            <DirectionsBusIcon/>
        <h2 className="font-bold text-2xl text-center ">Bus 3</h2>
        </div>
        <List alignItems="flex-start" sx={{ width: '100%', maxWidth: 360, bgcolor: '#cffafe' }}>
            {bus3Passengers.map((p) => <ListItem>
            <ListItemAvatar>
              <Avatar>
              <img src={gigaChad} ></img>
              </Avatar>
            </ListItemAvatar>
            <ListItemText primary={`${p.name} - ID# ${p.id}`} secondary={p.destination.destination}  />
            </ListItem>)}
        </List>
        </div>

        </div>
      );
}

export default BusList