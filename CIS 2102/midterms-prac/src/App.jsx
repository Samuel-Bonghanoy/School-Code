import {
  AddIcCallOutlined,
  EditNotifications,
  FavoriteBorder,
  NavigationRounded,
} from "@mui/icons-material";
import "./App.css";
import { Button, ButtonGroup, Fab } from "@mui/material";
// import Signin from "./SignIn";

function App() {
  return (
    <div
      className="bg-slate-400 h-screen overflow-y-auto 20"
      style={{ height: "120vh" }}
    >
      <p className="">yes</p>
      <Button variant="contained">suckadick</Button>
      {/* <Signin /> */}
      <ButtonGroup
        variant="contained"
        aria-label="outlined primary button group"
      >
        <Button>One</Button>
        <Button>Two</Button>
        <Button>Three</Button>
      </ButtonGroup>
      <div className="mt-5">
        <Fab color="primary" aria-label="add">
          <AddIcCallOutlined />
        </Fab>
        <Fab color="secondary" aria-label="edit">
          <EditNotifications />
        </Fab>
        <Fab variant="extended">
          <NavigationRounded sx={{ mr: 1 }} />
          Navigate
        </Fab>
        <Fab disabled aria-label="like">
          <FavoriteBorder />
        </Fab>
      </div>
    </div>
  );
}

export default App;
