import { useState } from "react";

function ContactList({ contacts, setContacts }) {
  const handleDeleteContact = (id) => {
    setContacts((prevContacts) =>
      prevContacts.filter((contact) => contact.id !== id)
    );
  };

  return (
    <>
      <ul className=" w-fit text-center mx-auto mt-5 flex gap-5">
        {contacts.map((contact) => {
          return (
            <li
              key={contact.id}
              className="flex flex-col px-10 py-5 relative bg-green-300 w-fit rounded"
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
      )}
    </>
  );
}

export default ContactList;
