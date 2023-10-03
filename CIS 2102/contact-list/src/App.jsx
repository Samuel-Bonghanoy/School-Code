import { useState } from "react";
import "./App.css";
import Form from "./Form";
import ContactList from "./ContactList";

function App() {
  const [contacts, setContacts] = useState([]);
  return (
    <div className="text-center bg-midnight h-screen">
      <h1 className="text-2xl font-bold text-slate-200 py-4">Contact Book</h1>
      <Form contacts={contacts} setContacts={setContacts} />
      <ContactList contacts={contacts} setContacts={setContacts} />
    </div>
  );
}

export default App;
