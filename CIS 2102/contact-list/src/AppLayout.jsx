import { useState } from "react";
import ContactList from "./ContactList";
import Form from "./Form";
import { Link } from "react-router-dom";

function AppLayout() {
  const [contacts, setContacts] = useState([]);
  return (
    <div className="text-center bg-midnight h-screen">
      <h1 className="text-2xl font-bold text-slate-200 py-4">Contact Book</h1>
      <Form contacts={contacts} setContacts={setContacts} />
      <ContactList contacts={contacts} setContacts={setContacts} />
      <Link to="/">
        <div className="bg-red-500 text-white p-2 rounded"></div>
        {/* <button className="">
    Edit Contact
  </button> */}
      </Link>
    </div>
  );
}

export default AppLayout;
