const express = require("express");
const expressLayouts = require("express-ejs-layouts");
const {
	loadContact,
	findContact,
	addContact,
	cekDuplikat,
	deleteContact,
	updateContacts,
} = require("./utils/contacts");
const { body, validationResult, check } = require("express-validator");
const session = require("express-session");
const cookieParser = require("cookie-parser");
const flash = require("connect-flash");

const app = express();
const port = 3000;

// Menginisialisasi express agar menggunakan ejs
app.set("view engine", "ejs");
app.use(expressLayouts); // third-party middleware
app.use(express.static("public")); // built-in middleware
app.use(express.urlencoded({ extended: true }));

// konfigurasi flash
app.use(cookieParser("secret"));
app.use(
	session({
		cookie: { maxAge: 6000 },
		secret: "secret",
		resave: true,
		saveUninitialized: true,
	})
);
app.use(flash());

app.get("/", (req, res) => {
	// res.sendFile("./index.html", { root: __dirname });
	const mahasiswa = [
		{
			nama: "Abil",
			email: "abilsabili50@gmail.com",
		},
		{
			nama: "Fahrul",
			email: "fahrul@gmail.com",
		},
		{
			nama: "Syaugi",
			email: "syaugiss@gmail.com",
		},
	];
	res.render("index", {
		nama: "Abil Sabili",
		title: "Halaman Home",
		mahasiswa,
		layout: "layouts/main-layout",
	});
});

app.get("/about", (req, res) => {
	res.render("about", {
		title: "Halaman About",
		layout: "layouts/main-layout",
	});
});

app.get("/contact", (req, res) => {
	const contacts = loadContact();

	res.render("contact", {
		title: "Halaman Contact",
		layout: "layouts/main-layout",
		contacts,
		msg: req.flash("msg"),
	});
});

// Halaman form tambah data
app.get("/contact/add", (req, res) => {
	res.render("add-contact", {
		title: "Tambah Data Kontak",
		layout: "layouts/main-layout",
	});
});

// proses data kontak
app.post(
	"/contact",
	[
		body("nama").custom((value) => {
			const duplikat = cekDuplikat(value);
			if (duplikat) {
				throw new Error("Nama Contact sudah digunakan!");
			}
			return true;
		}),
		check("email", "Email tidak valid").isEmail(),
		check("noHP", "No HP tidak valid").isMobilePhone("id-ID"),
	],
	(req, res) => {
		const errors = validationResult(req);
		if (!errors.isEmpty()) {
			// return res.status(400).json({ errors: errors.array() });
			res.render("add-contact", {
				title: "Tambah Data Kontak",
				layout: "layouts/main-layout",
				errors: errors.array(),
			});
		} else {
			addContact(req.body);
			req.flash("msg", "Data Kontak Berhasil Ditambahkan!");
			res.redirect("/contact");
		}
	}
);

app.get("/contact/delete/:nama", (req, res) => {
	const contact = findContact(req.params.nama);

	// jika kontak tidak ada
	if (!contact) {
		res.status(404);
		res.send("<h1>404</h1>");
	} else {
		deleteContact(req.params.nama);
		req.flash("msg", "Data Kontak Berhasil Dihapus!");
		res.redirect("/contact");
	}
});

// halaman form ubah data contact
app.get("/contact/edit/:nama", (req, res) => {
	const contact = findContact(req.params.nama);
	res.render("edit-contact", {
		title: "Tambah Data Kontak",
		layout: "layouts/main-layout",
		contact,
	});
});

// proses ubah data
app.post(
	"/contact/update",
	[
		body("nama").custom((value, { req }) => {
			const duplikat = cekDuplikat(value);
			if (value !== req.body.oldNama && duplikat) {
				throw new Error("Nama Contact sudah digunakan!");
			}
			return true;
		}),
		check("email", "Email tidak valid").isEmail(),
		check("noHP", "No HP tidak valid").isMobilePhone("id-ID"),
	],
	(req, res) => {
		const errors = validationResult(req);
		if (!errors.isEmpty()) {
			// return res.status(400).json({ errors: errors.array() });
			res.render("edit-contact", {
				title: "Ubah Data Kontak",
				layout: "layouts/main-layout",
				errors: errors.array(),
				contact: req.body,
			});
		} else {
			updateContacts(req.body);
			req.flash("msg", "Data Kontak Berhasil Diubah!");
			res.redirect("/contact");
		}
	}
);

// Halaman detail contact
app.get("/contact/:nama", (req, res) => {
	const contact = findContact(req.params.nama);

	res.render("detail", {
		title: "Halaman Detail Contact",
		layout: "layouts/main-layout",
		contact,
	});
});

app.use("/", (req, res) => {
	res.status(404);
	res.send("<h1>404</h1>");
});

app.listen(port, () => {
	console.log("Example app listening at http://localhost:" + port);
});
