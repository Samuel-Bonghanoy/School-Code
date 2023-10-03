import { useState } from "react";

function Form({ contacts, setContacts }) {
  const [editing, setEditing] = useState(false);
  const [newContact, setNewContact] = useState({
    name: "",
    age: "",
    contactNumber: "",
    id: "",
    course: "",
  });

  const [editContact, setEditContact] = useState({
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

  const handleEdit = (e) => {
    e.preventDefault();
    const { name, value } = e.target;
    setEditContact((prevContact) => ({
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
      setNewContact({
        name: "",
        age: "",
        contactNumber: "",
        id: "",
        course: "",
      });
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

  const handleEditContact = (id) => {};

  return (
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
        <button
          className="bg-purple-500 text-white p-2 rounded"
          onClick={(e) => {
            e.preventDefault();
            setEditing(true);
          }}
        >
          Edit Contact
        </button>
      </form>
      {editing && (
        <div className="absolute top-[25%] left-1/2 transform -translate-x-1/2 -translate-y-1/2 h-[50%] bg-purple-300 w-6/12 text-center mt-5 z-40 pb-3 items-center flex flex-col pt-5">
          <h2 className="font-bold mb-2">Edit Contact</h2>
          <form className="flex flex-col space-y-2 w-3/6 ">
            <input
              className="border p-2 rounded"
              type="text"
              name="ID"
              placeholder="ID to edit"
              value={newContact.id}
              onChange={handleEdit}
            />
            {editContact.id && (
              <>
                <input
                  className="border p-2 rounded"
                  type="text"
                  name="name"
                  placeholder="Name"
                  value={newContact.name}
                  onChange={handleEdit}
                />
                <input
                  className="border p-2 rounded"
                  type="text"
                  name="age"
                  placeholder="Age"
                  value={newContact.age}
                  onChange={handleEdit}
                />
                <input
                  className="border p-2 rounded"
                  type="text"
                  name="name"
                  placeholder="Name"
                  value={newContact.course}
                  onChange={handleEdit}
                />
              </>
            )}

            <button className="bg-green-500 text-white px-4 py-2 rounded-full border border-green-700 hover:bg-green-700 ">
              Save
            </button>
          </form>
        </div>
      )}
    </div>
  );
}

export default Form;