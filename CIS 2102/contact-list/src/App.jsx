import { useState } from "react";

import "./App.css";

function App() {
  const [contacts, setContacts] = useState([]);
  const [newContact, setNewContact] = useState({
    name: "",
    age: "",
    contactNumber: "",
    id: "",
    course: "",
  });

  const handleChange = (e) => {
    e.preventDefault();
    const { name, value } = e.target;
    setNewContact((prevContact) => ({
      ...prevContact,
      [name]: value,
    }));
  };

  const handleAddContact = (e) => {
    e.preventDefault();
    if (
      !newContact.id ||
      contacts.find((contact) => contact.id === newContact.id)
    ) {
      alert("Please provide a unique ID# or check if ID# already exists.");
      return;
    }

    setContacts([...contacts, newContact]);
    setNewContact({
      name: "",
      age: "",
      contactNumber: "",
      id: "",
      course: "",
    });
  };

  const handleDeleteContact = (id) => {
    setContacts((prevContacts) =>
      prevContacts.filter((contact) => contact.id !== id)
    );
  };

  return (
    <div className="text-center bg-midnight h-screen">
      <h1 className="text-2xl font-bold text-slate-200 py-4">Contact Book</h1>
      <div className="mx-auto w-6/12">
        <form className="flex flex-col space-y-2">
          <input
            className="border p-2 rounded"
            type="text"
            name="name"
            placeholder="Name"
            value={newContact.name}
            onChange={handleChange}
          />
          <input
            className="border p-2 rounded"
            type="number"
            name="age"
            placeholder="Age"
            value={newContact.age}
            onChange={handleChange}
          />
          <input
            className="border p-2 rounded"
            type="text"
            name="contactNumber"
            placeholder="Contact Number"
            value={newContact.contactNumber}
            onChange={handleChange}
          />
          <input
            className="border p-2 rounded"
            type="text"
            name="id"
            placeholder="ID#"
            value={newContact.id}
            onChange={handleChange}
          />
          <input
            className="border p-2 rounded"
            type="text"
            name="course"
            placeholder="Course"
            value={newContact.course}
            onChange={handleChange}
          />
          <button
            className="bg-blue-500 text-white p-2 rounded"
            onClick={handleAddContact}
          >
            Add Contact
          </button>
        </form>
      </div>
      <ul className="bg-green-300 w-6/12 text-center mx-auto mt-5">
        {contacts.map((contact) => {
          return (
            <li key={contact.id} className="flex flex-col">
              <p>Name: {contact.name}</p> - {contact.age} years old - ID#
              <p>Age: {contact.age} Y.O</p> - {contact.age} years old - ID#
              <p>ID: {contact.name}</p> - {contact.age} years old - ID#
              <p>Name: {contact.name}</p> - {contact.age} years old - ID#
              {contact.id} - {contact.course}
              <button onClick={() => handleDeleteContact(contact.id)}>
                Delete
              </button>
            </li>
          );
        })}
      </ul>
    </div>
  );
}

export default App;
