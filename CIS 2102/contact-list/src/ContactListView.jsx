import { useEffect, useState } from "react";
import { Link } from "react-router-dom";

function ContactList() {
  const [contacts, setContacts] = useState([]);

  useEffect(() => {
    async function getContacts() {
      const res = await fetch("http://localhost:9000/contacts");
      const data = await res.json();

      setContacts(data);
    }
    console.log("yesd");
    getContacts();
  }, [setContacts, contacts]);

  const handleDeleteContact = async (id) => {
    await fetch(`http://localhost:9000/contacts/${id}`, {
      method: "DELETE",
    });

    console.log("yes");
    setContacts((prevContacts) =>
      prevContacts.filter((contact) => contact.id !== id)
    );
  };

  return (
    <div className="h-screen w-screen bg-midnight pt-10">
      <ul className=" w-fit text-center mx-auto mt-5 flex gap-5">
        {contacts.map((contact) => {
          return (
            <li
              key={contact.id}
              className="flex flex-col px-10 py-5 relative bg-green-300 w-fit rounded mt-5"
            >
              <div className="flex flex-col items-start mx-2">
                <p>
                  <strong>Name:</strong> {contact.name}
                </p>
                <p>
                  <strong>Age:</strong> {contact.age}
                </p>
                <p>
                  <strong>ID:</strong> {contact.id}
                </p>
                <p>
                  <strong>Contact Number:</strong> {contact.contactNumber}
                </p>
                <p>
                  <strong>Course:</strong> {contact.course}
                </p>
              </div>
              <button
                className="bg-red-500 text-white px-4 py-2 rounded-full border border-red-500 hover:bg-red-900 mt-3"
                onClick={() => handleDeleteContact(contact.id)}
              >
                Delete
              </button>
            </li>
          );
        })}
      </ul>
      )
      <Link to="/">
        <div className="bg-red-500 text-white p-2 rounded mx-auto w-6/12 h-10 text-center">
          <p>Form View</p>
        </div>
      </Link>
    </div>
  );
}

export default ContactList;
