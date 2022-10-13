const fs = require("fs");

// membuat folder data (jika tidak ada)
const dirPath = "./data";
if (!fs.existsSync(dirPath)) {
	fs.mkdirSync(dirPath);
}

// membuat file contacts.json (jika belum ada)
const filePath = "./data/contacts.json";
if (!fs.existsSync(filePath)) {
	fs.writeFileSync(filePath, "[]", "utf-8");
}

// ambil semua data di contact.json
const loadContact = () => {
	const file = fs.readFileSync(filePath, "utf-8");
	return JSON.parse(file);
};

// cari contact berdasarkan nama
const findContact = (nama) => {
	const contacts = loadContact();
	const contact = contacts.find(
		(contact) => contact.nama.toLowerCase() === nama.toLowerCase()
	);
	return contact;
};

// Menimpa file contacts.json dgn data baru
const saveContacts = (contacts) => {
	fs.writeFileSync(filePath, JSON.stringify(contacts));
};

// Menambahkan data kontak baru
const addContact = (contact) => {
	const contacts = loadContact();
	contacts.push(contact);
	saveContacts(contacts);
};

// Mengecek nama yang duplikat
const cekDuplikat = (nama) => {
	const contacts = loadContact();
	return contacts.find((contact) => contact.nama === nama);
};

// Hapus kontak
const deleteContact = (nama) => {
	const contacts = loadContact();
	const newContacts = contacts.filter((contact) => contact.nama !== nama);
	saveContacts(newContacts);
};

// Mengubah contact
const updateContacts = (contactBaru) => {
	const contacts = loadContact();

	for (let i = 0; i < contacts.length; i++) {
		if (contacts[i].nama == contactBaru.oldNama) {
			contacts[i].nama = contactBaru.nama;
			contacts[i].email = contactBaru.email;
			contacts[i].noHP = contactBaru.noHP;
		}
	}
	saveContacts(contacts);
};

module.exports = {
	loadContact,
	findContact,
	addContact,
	cekDuplikat,
	deleteContact,
	updateContacts,
};
