#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

// Struct untuk menyimpan informasi tiket
struct Ticket {
	string passengerName;
	string gender;
	string phoneNumber;
	string tanggal;
	string origin;
	string destination;
	string flightSchedule;
	string seatNumber;
	string bookingNumber;
	string flightMaskapai;
	string flightPrice;
};

// Struct untuk menyimpan informasi penerbangan
struct Flight {
	string airline;
	string departure;
	string arrival;
	string price;
	string category;
};

// Struktur data stack untuk menyimpan kursi yang tersedia
struct SeatStack {
	int capacity;
	int top;
	string* seats;

	SeatStack(int capacity) {
		this->capacity = capacity;
		top = -1;
		seats = new string[capacity];
	}

	bool isFull() {
		return top == capacity - 1;
	}

	bool isEmpty() {
		return top == -1;
	}

	void push(string seat) {
		if (isFull()) {
			cout << "Kursi sudah penuh." << endl;
		} else {
			seats[++top] = seat;
		}
	}

	bool removeSeat(string seat) {
		int seatIndex = -1;
		for (int i = 0; i <= top; i++) {
			if (seats[i] == seat) {
				seatIndex = i;
				break;
			}
		}

		if (seatIndex == -1) {
			cout << "Kursi tidak ditemukan." << endl;
			return false;
		} else {
			for (int i = seatIndex; i < top; i++) {
				seats[i] = seats[i + 1];
			}
			top--;

			return true;
		}
	}

	void displayAvailableSeats() {
		cout << "Kursi yang tersedia: ";
		if (isEmpty()) {
			cout << "Tidak ada kursi tersedia." << endl;
		} else {
			for (int i = 0; i <= top; i++) {
				cout << seats[i] << " ";
			}
			cout << endl;
		}
	}
};
// Struktur data linked list untuk menyimpan informasi tiket
struct TicketLinkedList {
	Ticket ticket;
	TicketLinkedList* next;

	TicketLinkedList(Ticket ticket) {
		this->ticket = ticket;
		next = nullptr;
	}
};

// Struktur data linked list untuk menyimpan informasi pengguna terdaftar
struct UserLinkedList {
	string username;
	string password;
	UserLinkedList* next;

	UserLinkedList(string username, string password) {
		this->username = username;
		this->password = password;
		next = nullptr;
	}
};

// Fungsi untuk mencari nomor kursi pada array
int searchSeatNumber(string* seats, int size, string seatNumber) {
	for (int i = 0; i < size; i++) {
		if (seats[i] == seatNumber) {
			return i;
		}
	}
	return -1;
}

// Fungsi untuk mengurutkan kursi dalam array
void sortSeats(string* seats, int size) {
	sort(seats, seats + size);
}

// Fungsi untuk melakukan login
bool login(UserLinkedList* users, string username, string password) {
	UserLinkedList* curr = users;
	while (curr != nullptr) {
		if (curr->username == username && curr->password == password) {
			return true;
		}
		curr = curr->next;
	}
	return false;
}

// Fungsi untuk melakukan register
void registerUser(UserLinkedList*& users, string username, string password) {
	UserLinkedList* newUser = new UserLinkedList(username, password);
	newUser->next = users;
	users = newUser;

	cout << "Pengguna berhasil terdaftar." << endl;
}

// FungFungsi untuk menampilkan pilihan penerbangan
void displayFlights(const vector<Flight>& flights) {
	cout << "=============================== Penerbangan Ditemukan ===============================" << endl;
	cout << "|       Airline:   Departure:       Arrival:      Price:           Category:        |" << endl;
	cout << "====================================================================================="<<endl;
	for (int i = 0; i < flights.size(); i++) {
		cout << "|" << setw(2) << i+1 << ". " << setw(10) << flights[i].airline << "\t" << setw(10) << flights[i].departure << "\t" << setw(10) << flights[i].arrival << "\t" << setw(8) << flights[i].price << "\t" << setw(12) << flights[i].category << "        |" << endl;
	}
	cout << "====================================================================================="<<endl;
}

void doPayment(string bookingNumber, int amount) {
	string bankName, accountNumber;
	cout << "Masukkan nama bank: ";
	cin >> bankName;
	cout << "Masukkan nomor rekening: ";
	cin >> accountNumber;
	cout << "Masukkan Jumlah Pembayaran: ";
	cin >> amount ;

	// Proses transfer
	// Implementasikan logika transfer sesuai dengan kebutuhan

	cout << "Pembayaran tiket dengan nomor booking " << bookingNumber << " berhasil dilakukan." << endl;
	cout << "Jumlah yang dibayarkan: " <<amount<<endl;
	cout << "Bank: " << bankName << endl;
	cout << "Nomor Rekening: " << accountNumber << endl;
}

// Fungsi untuk melakukan pembayaran tiket
void makePayment(TicketLinkedList* bookedTickets) {
	string bookingNumber;
	cout << "Masukkan nomor booking tiket: ";
	cin >> bookingNumber;

	TicketLinkedList* curr = bookedTickets;
	bool found = false;

	while (curr != nullptr) {
		if (curr->ticket.bookingNumber == bookingNumber) {
			found = true;
			break;
		}
		curr = curr->next;
	}

	if (found) {
		int amount;
		cout << "Total jumlah yang harus dibayarkan: " <<curr->ticket.flightPrice<<endl;
		cout << "Pembayaran atas nama: " <<curr->ticket.passengerName<<endl;
		doPayment(bookingNumber, amount);
	} else {
		cout << "Nomor booking tidak ditemukan." << endl;
	}
}

void jadwal() {
	int waktu[18] = { 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23 };
	int* ptrX;
	ptrX = waktu;

	cout << "             [ Jadwal Keberangkatan Dan Kedatangan Pesawat ]         " << endl;
	cout << "   ---------------------------------------------------------------------------------------------------------" << endl;
	cout << "   |No. |      Keberangkatan           |     Category     |     Maskapai     |               Waktu         |    " << endl;
	cout << "   ---------------------------------------------------------------------------------------------------------" << endl;
	cout << "   |    |                              |   Bussiness      |      Garuda      |          ""0" << ptrX[2] << ".00  -> " << ptrX[4]  << ".00    |" << endl;
	cout << "   | 1. | Jakarta - Surabaya           |   Bussiness      |      Lion Air    |          ""0" << ptrX[3] << ".00  -> " << ptrX[11]  << ".00    |" << endl;
	cout << "   |    |                              |                  |                  |                             |"<< endl;
	cout << "   ---------------------------------------------------------------------------------------------------------" << endl;
	cout << "   |    |                              |                  |                  |                             |"  << endl;
	cout << "   | 2. | Jakarta - Bali               |   Bussiness      |      Emirate     |          " << ptrX[13] << ".00  -> " << ptrX[16] << ".00    |" << endl;
	cout << "   |    |                              |                  |                  |                             |"  << endl;
	cout << "   ---------------------------------------------------------------------------------------------------------" << endl;
	cout << "   |    |                              |                  |                  |                             |"<< endl;
	cout << "   | 3. | Jakarta - Yogyakarta         |   Bussiness      |      Citilink    |          " << ptrX[15] << ".00 -> " << ptrX[17]   << ".00     |" << endl;
	cout << "   |    |                              |                  |                  |                             |" << endl;
	cout << "   ---------------------------------------------------------------------------------------------------------" << endl;
	cout << "   |    |                              |   Bussiness      |      Garuda      |          ""0" << ptrX[1] << ".00 -> ""0" << ptrX[3]   << ".00     |" << endl;
	cout << "   | 4. | Surabaya - Jakarta           |   Bussiness      |      Lion Air    |          ""0" << ptrX[2] << ".00 -> " << ptrX[4]   << ".00     |" << endl;
	cout << "   |    |                              |                  |                  |                             |" << endl;
	cout << "   ---------------------------------------------------------------------------------------------------------" << endl;
	cout << "   |    |                              |   Bussiness      |      Garuda      |          " << ptrX[4] << ".00 -> " << ptrX[6]   << ".00     |" << endl;
	cout << "   | 5. | Surabaya - Bali              |   Bussiness      |      Emirate     |          " << ptrX[7] << ".00 -> " << ptrX[9]   << ".00     |" << endl;
	cout << "   |    |                              |                  |                  |                             |" << endl;
	cout << "   ---------------------------------------------------------------------------------------------------------" << endl;
	cout << "   |    |                              |   Bussiness      |      Garuda      |          " << ptrX[9] << ".00 -> " << ptrX[11]   << ".00     |" << endl;
	cout << "   | 6. | Surabaya - Yogyakarta        |   Bussiness      |      Citilink    |          " << ptrX[12] << ".00 -> " << ptrX[14]   << ".00     |" << endl;
	cout << "   |    |                              |                  |                  |                             |" << endl;
	cout << "   ---------------------------------------------------------------------------------------------------------" << endl;
	cout << "   |    |                              |                  |                  |                             |" << endl;
	cout << "   | 7. | Bali - Jakarta               |   Bussiness      |      Emirate     |          ""0" << ptrX[3] << ".00 -> " << ptrX[5]   << ".00     |" << endl;
	cout << "   |    |                              |                  |                  |                             |" << endl;
	cout << "   ---------------------------------------------------------------------------------------------------------" << endl;
	cout << "   |    |                              |   Bussiness      |      Garuda      |          " << ptrX[5] << ".00 -> " << ptrX[7]   << ".00     |" << endl;
	cout << "   | 8. | Bali - Surabaya              |   Bussiness      |      Emirate     |          " << ptrX[8] << ".00 -> " << ptrX[10]   << ".00     |" << endl;
	cout << "   |    |                              |                  |                  |                             |" << endl;
	cout << "   ---------------------------------------------------------------------------------------------------------" << endl;
	cout << "   |    |                              |                  |                  |                             |" << endl;
	cout << "   | 9. | Bali - Yogyakarta            |   Bussiness      |      Batik Air   |          " << ptrX[10] << ".00 -> " << ptrX[12]   << ".00     |" << endl;
	cout << "   |    |                              |                  |                  |                             |" << endl;
	cout << "   ---------------------------------------------------------------------------------------------------------" << endl;
	cout << "   |    |                              |                  |                  |                             |" << endl;
	cout << "   | 10.| Yogyakarta - Jakarta         |   Bussiness      |      Citilink    |          ""0" << ptrX[2] << ".00 -> " << ptrX[4]   << ".00     |" << endl;
	cout << "   |    |                              |                  |                  |                             |" << endl;
	cout << "   ---------------------------------------------------------------------------------------------------------" << endl;
	cout << "   |    |                              |                  |                  |                             |" << endl;
	cout << "   | 11.| Yogyakarta - Surabaya        |   Bussiness      |      Citilink    |          " << ptrX[6] << ".00 -> " << ptrX[8]   << ".00     |" << endl;
	cout << "   |    |                              |                  |                  |                             |" << endl;
	cout << "   ---------------------------------------------------------------------------------------------------------" << endl;
	cout << "   |    |                              |                  |                  |                             |" << endl;
	cout << "   | 12.| Bali - Jakarta               |   Bussiness      |      Emirate     |          ""0" << ptrX[3] << ".00 -> " << ptrX[5]   << ".00     |" << endl;
	cout << "   |    |                              |                  |                  |                             |" << endl;
	cout << "   ---------------------------------------------------------------------------------------------------------" << endl;
	cout << "   |    |                              |   Bussiness      |      Garuda      |          " << ptrX[5] << ".00 -> " << ptrX[7]   << ".00     |" << endl;
	cout << "   | 13.| Bali - Surabaya              |   Bussiness      |      Emirate     |          " << ptrX[8] << ".00 -> " << ptrX[10]   << ".00     |" << endl;
	cout << "   |    |                              |                  |                  |                             |" << endl;
	cout << "   ---------------------------------------------------------------------------------------------------------" << endl;
	cout << "   |    |                              |                  |                  |                             |" << endl;
	cout << "   | 14.| Bali - Yogyakarta            |   Bussiness      |      Batik Air   |          " << ptrX[10] << ".00 -> " << ptrX[12]   << ".00     |" << endl;
	cout << "   |    |                              |                  |                  |                             |" << endl;
	cout << "   ---------------------------------------------------------------------------------------------------------" << endl;
	cout << "   |    |                              |                  |                  |                             |" << endl;
	cout << "   | 15.| Yogyakarta - Jakarta         |   Bussiness      |      Citilink    |          ""0" << ptrX[2] << ".00 -> " << ptrX[4]   << ".00     |" << endl;
	cout << "   |    |                              |                  |                  |                             |" << endl;
	cout << "   ---------------------------------------------------------------------------------------------------------" << endl;
	cout << "   |    |                              |                  |                  |                             |" << endl;
	cout << "   | 16.| Yogyakarta - Surabaya        |   Bussiness      |      Citilink    |          " << ptrX[6] << ".00 -> " << ptrX[8]   << ".00     |" << endl;
	cout << "   |    |                              |                  |                  |                             |" << endl;
	cout << "   ---------------------------------------------------------------------------------------------------------" << endl;
	cout << "   |    |                              |                  |                  |                             |" << endl;
	cout << "   | 17.| Yogyakarta - Bali            |   Bussiness      |      Batik Air   |          " << ptrX[12] << ".00 -> " << ptrX[14]   << ".00     |" << endl;
	cout << "   |    |                              |                  |                  |                             |" << endl;
	cout << "   --------------------------------------------------------------------------------------------- -----------" << endl;
	cout << "   |    |                              |   Economy        |    Sriwijaya Air |          ""0" << ptrX[2] << ".30  -> " << ptrX[4]  << ".30    |" << endl;
	cout << "   | 18.| Jakarta - Surabaya           |   Economy        |      Air Asia    |          " << ptrX[4] << ".30  -> " << ptrX[6]  << ".30    |" << endl;
	cout << "   |    |                              |                  |                  |                             |"<< endl;
	cout << "   ---------------------------------------------------------------------------------------------------------" << endl;
	cout << "   |    |                              |   Economy        |      Air Asia    |          " << ptrX[7] << ".30  -> " << ptrX[9] << ".30    |"  << endl;
	cout << "   | 19.| Jakarta - Bali               |   Economy        |      Citilink    |          " << ptrX[10] << ".30  -> " << ptrX[12] << ".30    |" << endl;
	cout << "   |    |                              |                  |                  |                             |"<< endl;
	cout << "   ---------------------------------------------------------------------------------------------------------" << endl;
	cout << "   |    |                              |                  |                  |                             |"<< endl;
	cout << "   | 20.| Jakarta - Yogyakarta         |   Economy        |      Citilink    |          " << ptrX[13] << ".30 -> " << ptrX[15]   << ".30     |" << endl;
	cout << "   |    |                              |                  |                  |                             |" << endl;
	cout << "   ---------------------------------------------------------------------------------------------------------" << endl;
	cout << "   |    |                              |   Economy        |    Sriwijaya Air |          ""0" << ptrX[1] << ".30 -> ""0" << ptrX[3]   << ".30     |" << endl;
	cout << "   | 21.| Surabaya - Jakarta           |   Economy        |      Lion Air    |          ""0" << ptrX[3] << ".30 -> " << ptrX[5]   << ".30     |" << endl;
	cout << "   |    |                              |                  |                  |                             |" << endl;
	cout << "   ---------------------------------------------------------------------------------------------------------" << endl;
	cout << "   |    |                              |   Economy        |      Air Asia    |          " << ptrX[6] << ".30 -> " << ptrX[8]   << ".30     |" << endl;
	cout << "   | 22.| Surabaya - Bali              |   Economy        |      Citilink    |          " << ptrX[9] << ".30 -> " << ptrX[11]   << ".30     |" << endl;
	cout << "   |    |                              |                  |                  |                             |" << endl;
	cout << "   ---------------------------------------------------------------------------------------------------------" << endl;
	cout << "   |    |                              |   Economy        |    Sriwijaya Air |          " << ptrX[12] << ".30 -> " << ptrX[14]   << ".30     |" << endl;
	cout << "   | 23.| Surabaya - Yogyakarta        |   Economy        |      Air Asia    |          " << ptrX[15] << ".30 -> " << ptrX[17]   << ".30     |" << endl;
	cout << "   |    |                              |                  |                  |                             |" << endl;
	cout << "   ---------------------------------------------------------------------------------------------------------" << endl;
	cout << "   |    |                              |   Economy        |      Air Asia    |          ""0" << ptrX[2] << ".30 -> " << ptrX[4]   << ".30     |" << endl;
	cout << "   | 24.| Bali - Jakarta               |   Economy        |      Lion Air    |          " << ptrX[5] << ".30 -> " << ptrX[7]   << ".30     |" << endl;
	cout << "   |    |                              |                  |                  |                             |" << endl;
	cout << "   ---------------------------------------------------------------------------------------------------------" << endl;
	cout << "   |    |                              |   Economy        |      Air Asia    |          " << ptrX[8] << ".30 -> " << ptrX[10]   << ".30     |" << endl;
	cout << "   | 25.| Bali - Surabaya              |   Economy        |      Citilink    |          " << ptrX[11] << ".30 -> " << ptrX[13]   << ".30     |" << endl;
	cout << "   |    |                              |                  |                  |                             |" << endl;
	cout << "   ---------------------------------------------------------------------------------------------------------" << endl;
	cout << "   |    |                              |                  |                  |                             |" << endl;
	cout << "   | 26.| Bali - Yogyakarta            |   Economy        |      Batik Air   |          " << ptrX[14] << ".30 -> " << ptrX[16]   << ".30     |" << endl;
	cout << "   |    |                              |                  |                  |                             |" << endl;
	cout << "   ---------------------------------------------------------------------------------------------------------" << endl;
	cout << "   |    |                              |   Economy        |      Citilink    |          ""0" << ptrX[1] << ".30 -> ""0" << ptrX[3]  << ".30     |" << endl;
	cout << "   | 27.| Yogyakarta - Jakarta         |   Economy        |      Lion Air    |          ""0" << ptrX[2] << ".30 -> ""0" << ptrX[4]   << ".30    |" << endl;
	cout << "   |    |                              |                  |                  |                             |" << endl;
	cout << "   ---------------------------------------------------------------------------------------------------------" << endl;
	cout << "   |    |                              |    Economy       |      Air Asia    |          " << ptrX[6] << ".30 -> " << ptrX[8]   << ".30     |" << endl;
	cout << "   | 28.| Yogyakarta - Surabaya        |    Economy       |   Sriwijaya Air  |          " << ptrX[9] << ".30 -> " << ptrX[11]   << ".30     |" << endl;
	cout << "   |    |                              |                  |                  |                             |" << endl;
	cout << "   ---------------------------------------------------------------------------------------------------------" << endl;
	cout << "   |    |                              |                  |                  |                             |" << endl;
	cout << "   | 29.| Bali - Jakarta               |   Economy        |      Batik Air   |          " << ptrX[12] << ".30 -> " << ptrX[14]   << ".30     |" << endl;
	cout << "   |    |                              |                  |                  |                             |" << endl;
	cout << "   ---------------------------------------------------------------------------------------------------------" << endl;
	cout << "   |    |                              |   Bussiness      |      Garuda      |          " << ptrX[5] << ".00 -> " << ptrX[7]   << ".00     |" << endl;
	cout << "   | 30.| Bali - Surabaya              |   Bussiness      |      Emirate     |          " << ptrX[8] << ".00 -> " << ptrX[10]   << ".00     |" << endl;
	cout << "   |    |                              |                  |                  |                             |" << endl;
	cout << "   ---------------------------------------------------------------------------------------------------------" << endl;
	cout << "   |    |                              |                  |                  |                             |" << endl;
	cout << "   | 31.| Bali - Yogyakarta            |   Bussiness      |      Batik Air   |          " << ptrX[10] << ".00 -> " << ptrX[12]   << ".00     |" << endl;
	cout << "   |    |                              |                  |                  |                             |" << endl;
	cout << "   ---------------------------------------------------------------------------------------------------------" << endl;
	cout << "   |    |                              |                  |                  |                             |" << endl;
	cout << "   | 32.| Yogyakarta - Jakarta         |   Bussiness      |      Citilink    |          ""0" << ptrX[2] << ".00 -> " << ptrX[4]   << ".00     |" << endl;
	cout << "   |    |                              |                  |                  |                             |" << endl;
	cout << "   ---------------------------------------------------------------------------------------------------------" << endl;
	cout << "   |    |                              |                  |                  |                             |" << endl;
	cout << "   | 33.| Yogyakarta - Surabaya        |   Bussiness      |      Citilink    |          " << ptrX[6] << ".00 -> " << ptrX[8]   << ".00     |" << endl;
	cout << "   |    |                              |                  |                  |                             |" << endl;
	cout << "   ---------------------------------------------------------------------------------------------------------" << endl;
	cout << "   |    |                              |                  |                  |                             |" << endl;
	cout << "   | 34.| Yogyakarta - Bali            |   Bussiness      |      Batik Air   |          " << ptrX[12] << ".00 -> " << ptrX[14]   << ".00     |" << endl;
	cout << "   |    |                              |                  |                  |                             |" << endl;
	cout << "   ---------------------------------------------------------------------------------------------------------" << endl;
	cout << endl;
}

int main() {
	const int totalSeats = 10;
	string seats[totalSeats] = {"1A", "2B", "3C", "4D", "5E", "6F", "7G", "8H", "9I", "10J"};
	SeatStack availableSeats(totalSeats);

	// Mengisi stack dengan kursi yang tersedia
	for (int i = totalSeats - 1; i >= 0; i--) {
		availableSeats.push(seats[i]);
	}

	TicketLinkedList* bookedTickets = nullptr;
	UserLinkedList* registeredUsers = nullptr;

	while (true) {
		cout << "=== SISTEM TIKETING PESAWAT ONLINE ===" << endl;
		cout << "1. Login" << endl;
		cout << "2. Register" << endl;
		cout << "3. Keluar" << endl;
		cout << "Pilih menu: ";
		int choice;
		cin >> choice;

		if (choice == 1) {
			// Login
			string username, password;
			system("cls");
			cout << "Masukkan username: ";
			cin >> username;
			cout << "Masukkan password: ";
			cin >> password;

			if (login(registeredUsers, username, password)) {
				cout << "Login berhasil." << endl;
				// Masuk ke menu utama untuk memesan tiket
				while (true) {
					cout << "=== MENU UTAMA ===" << endl;
					cout << "1. Pesan Tiket" << endl;
					cout << "2. Batalkan Tiket" << endl;
					cout << "3. Tampilkan Tiket" << endl;
					cout << "4. Tampilkan Penerbangan Yang Tersedia" << endl;
					cout << "5. Lakukan Pembayaran " <<endl;
					cout << "6. Logout" << endl;
					cout << "Pilih menu: ";
					cin >> choice;

					if (choice == 1) {
						// Pesan Tiket
						if (availableSeats.isEmpty()) {
							cout << "Tiket sudah habis." << endl;
						} else {
							string passengerName, gender, phoneNumber,tanggal, origin, destination, seatNumber;
							system("cls");
							cout << "Masukkan nama Anda: ";
							cin.ignore();
							getline(cin, passengerName);
							cout << "Masukkan jenis kelamin Anda (L/P): ";
							cin >> gender;
							cout << "Masukkan nomor telepon Anda: ";
							cin >> phoneNumber;
							cout << "Masukkan Tanggal Keberangkatan (DD/MM/YYYY): ";
							cin >> tanggal;

							cout << "Pilih kota asal:" << endl;
							cout << "1. Jakarta" << endl;
							cout << "2. Surabaya" << endl;
							cout << "3. Bali" << endl;
							cout << "4. Yogyakarta" << endl;
							cout << "Pilihan: ";
							int originChoice;
							cin >> originChoice;
							switch (originChoice) {
								case 1:
									origin = "Jakarta";
									break;
								case 2:
									origin = "Surabaya";
									break;
								case 3:
									origin = "Bali";
									break;
								case 4:
									origin = "Yogyakarta";
									break;
								default:
									cout << "Pilihan tidak valid." << endl;
									continue;
							}

							cout << "Pilih kota tujuan:" << endl;
							cout << "1. Jakarta" << endl;
							cout << "2. Surabaya" << endl;
							cout << "3. Bali" << endl;
							cout << "4. Yogyakarta" << endl;
							cout << "Pilihan: ";
							int destinationChoice;
							cin >> destinationChoice;
							switch (destinationChoice) {
								case 1:
									destination = "Jakarta";
									break;
								case 2:
									destination = "Surabaya";
									break;
								case 3:
									destination = "Bali";
									break;
								case 4:
									destination = "Yogyakarta";
									break;
								default:
									cout << "Pilihan tidak valid." << endl;
									continue;
							}

							cout << "Pilih kelas tiket:" << endl;
							cout << "1. Business" << endl;
							cout << "2. Economy" << endl;
							cout << "Pilihan: ";
							int classChoice;
							cin >> classChoice;

							vector<Flight> flights;
							if (classChoice == 1) {
								// Pilihan Business Class
								if (origin == "Jakarta") {
									if (destination == "Surabaya") {
										flights.push_back({"Garuda", "08:00", "10:00", "1.800.000", "Business"});
										flights.push_back({"Lion Air", "09:00", "11:00", "1.450.000", "Business"});
									} else if (destination == "Bali") {
										flights.push_back({"Emirate", "19:00", "22:00", "2.500.000", "Business"});
									} else if (destination == "Yogyakarta") {
										flights.push_back({"Citilink", "21:00", "23:00", "1.600.000", "Business"});
									}
								} else if (origin == "Surabaya") {
									if (destination == "Jakarta") {
										flights.push_back({"Garuda", "07:00", "09:00", "1.800.000", "Business"});
										flights.push_back({"Lion Air", "08:00", "10:00", "1.450.000", "Business"});
									} else if (destination == "Bali") {
										flights.push_back({"Garuda", "10:00", "12:00", "2.200.000", "Business"});
										flights.push_back({"Emirate", "13:00", "16:00", "2.500.000", "Business"});
									} else if (destination == "Yogyakarta") {
										flights.push_back({"Garuda", "15:00", "17:00", "1.900.000", "Business"});
										flights.push_back({"Citilink", "18:00", "20:00", "1.600.000", "Business"});
									}
								} else if (origin == "Bali") {
									if (destination == "Jakarta") {
										flights.push_back({"Emirate", "09:00", "12:00", "2.500.000", "Business"});
									} else if (destination == "Surabaya") {
										flights.push_back({"Garuda", "11:00", "13:00", "1.900.000", "Business"});
										flights.push_back({"Emirate", "14:00", "17:00", "2.200.000", "Business"});
									} else if (destination == "Yogyakarta") {
										flights.push_back({"Batik Air", "16:00", "18:00", "1.850.000", "Business"});
									}
								} else if (origin == "Yogyakarta") {
									if (destination == "Jakarta") {
										flights.push_back({"Citilink", "08:00", "10:00", "1.600.000", "Business"});
									} else if (destination == "Surabaya") {
										flights.push_back({"Citilink", "12:00", "14:00", "1.600.000", "Business"});
									} else if (destination == "Bali") {
										flights.push_back({"Batik Air", "18:00", "20:00", "1.850.000", "Business"});
									}
								}
								// Pilihan Economy Class
							} else if (classChoice == 2) {
								if (origin == "Jakarta") {
									if (destination == "Surabaya") {
										flights.push_back({"Sriwijaya Air", "07:30", "09:30", "900.000", "Economy"});
										flights.push_back({"AirAsia", "10:30", "12:30", "800.000", "Economy"});
									} else if (destination == "Bali") {
										flights.push_back({"AirAsia", "13:30", "15:30", "900.000", "Economy"});
										flights.push_back({"Citilink", "16:30", "18:30", "850.000", "Economy"});
									} else if (destination == "Yogyakarta") {
										flights.push_back({"Citilink", "19:30", "21:30", "800.000", "Economy"});
									}
								} else if (origin == "Surabaya") {
									if (destination == "Jakarta") {
										flights.push_back({"Sriwijaya Air", "06:30", "08:30", "900.000", "Economy"});
										flights.push_back({"Lion Air", "09:30", "11:30", "800.000", "Economy"});
									} else if (destination == "Bali") {
										flights.push_back({"AirAsia", "12:30", "14:30", "950.000", "Economy"});
										flights.push_back({"Citilink", "15:30", "17:30", "850.000", "Economy"});
									} else if (destination == "Yogyakarta") {
										flights.push_back({"Sriwijaya Air", "18:30", "20:30", "800.000", "Economy"});
										flights.push_back({"AirAsia", "21:30", "23:30", "750.000", "Economy"});
									}
								} else if (origin == "Bali") {
									if (destination == "Jakarta") {
										flights.push_back({"AirAsia", "08:30", "10:30", "950.000", "Economy"});
										flights.push_back({"Lion Air", "11:30", "13:30", "1.000.000", "Economy"});
									} else if (destination == "Surabaya") {
										flights.push_back({"AirAsia", "14:30", "16:30", "950.000", "Economy"});
										flights.push_back({"Citilink", "17:30", "19:30", "850.000", "Economy"});
									} else if (destination == "Yogyakarta") {
										flights.push_back({"Batik Air", "20:30", "22:30", "900.000", "Economy"});
									}
								} else if (origin == "Yogyakarta") {
									if (destination == "Jakarta") {
										flights.push_back({"Citilink", "06:30", "08:30", "800.000", "Economy"});
										flights.push_back({"Lion Air", "09:30", "11:30", "750.000", "Economy"});
									} else if (destination == "Surabaya") {
										flights.push_back({"AirAsia", "12:30", "14:30", "800.000", "Economy"});
										flights.push_back({"Sriwijaya Air", "15:30", "17:30", "750.000", "Economy"});
									} else if (destination == "Bali") {
										flights.push_back({"Batik Air", "18:30", "20:30", "900.000", "Economy"});
									}
								}
							} else {
								cout << "Pilihan tidak valid." << endl;
								continue;
							}

							displayFlights(flights);

							cout << "Pilih nomor penerbangan: ";
							int flightChoice;
							cin >> flightChoice;

							if (flightChoice < 1 || flightChoice > flights.size()) {
								cout << "Pilihan tidak valid." << endl;
								continue;
							}

							Flight selectedFlight = flights[flightChoice - 1];

							cout << "Pilih nomor kursi: ";
							availableSeats.displayAvailableSeats();
							cout << "Pilihan: ";
							cin >> seatNumber;

							int seatIndex = searchSeatNumber(seats, totalSeats, seatNumber);
							if (seatIndex == -1) {
								cout << "Kursi tidak valid." << endl;
								continue;
							}

							// Booking tiket
							string bookingNumber = to_string(bookedTickets != nullptr ? stoi(bookedTickets->ticket.bookingNumber) + 1 : 1);
							Ticket ticket;
							ticket.passengerName = passengerName;
							ticket.gender = gender;
							ticket.phoneNumber = phoneNumber;
							ticket.tanggal = tanggal;
							ticket.origin = origin;
							ticket.destination = destination;
							ticket.flightMaskapai = selectedFlight.airline;
							ticket.flightSchedule = selectedFlight.departure + " - " + selectedFlight.arrival;
							ticket.flightPrice = selectedFlight.price;
							ticket.seatNumber = seatNumber;
							ticket.bookingNumber = bookingNumber;

							// Menambahkan tiket ke linked list bookedTickets
							TicketLinkedList* newTicket = new TicketLinkedList(ticket);
							newTicket->next = bookedTickets;
							bookedTickets = newTicket;

							// Menghapus kursi dari stack availableSeats
							availableSeats.removeSeat(seatNumber);

							cout << "Tiket berhasil dipesan"<<endl;
							cout <<"Nomor booking anda: " << bookingNumber << endl;
						}
					} else if (choice == 2) {
						// Batalkan Tiket
						if (bookedTickets == nullptr) {
							cout << "Belum ada tiket yang dipesan." << endl;
							continue;
						}

						string bookingNumber;
						system("cls");
						cout << "Masukkan nomor booking tiket: ";
						cin >> bookingNumber;

						TicketLinkedList* curr = bookedTickets;
						TicketLinkedList* prev = nullptr;
						bool found = false;

						while (curr != nullptr) {
							if (curr->ticket.bookingNumber == bookingNumber) {
								found = true;
								break;
							}
							prev = curr;
							curr = curr->next;
						}

						if (found) {
							// Mengembalikan kursi ke stack availableSeats
							string seatNumber = curr->ticket.seatNumber;
							int seatIndex = searchSeatNumber(seats, totalSeats, seatNumber);
							if (seatIndex != -1) {
								seats[seatIndex] = seatNumber;
								sortSeats(seats, totalSeats);
							}

							// Menghapus tiket dari linked list bookedTickets
							if (prev == nullptr) {
								bookedTickets = curr->next;
							} else {
								prev->next = curr->next;
							}

							delete curr;
							cout << "Tiket berhasil dibatalkan." << endl;
						} else {
							cout << "Nomor booking tidak ditemukan." << endl;
						}
					} else if (choice == 3) {
						// Tampilkan Tiket
						if (bookedTickets == nullptr) {
							cout << "Belum ada tiket yang dipesan." << endl;
						} else {
							cout << "============== Tiket yang Dipesan ==============" << endl;
							TicketLinkedList* curr = bookedTickets;
							while (curr != nullptr) {
								cout << "| Nomor Booking         : " << setw(20) << left << curr->ticket.bookingNumber << " |" << endl;
								cout << "| Nama Penumpang        : " << setw(20) << left << curr->ticket.passengerName << " |" << endl;
								cout << "| Jenis Kelamin         : " << setw(20) << left << curr->ticket.gender << " |" << endl;
								cout << "| Nomor Telepon         : " << setw(20) << left << curr->ticket.phoneNumber << " |" << endl;
								cout << "| Tanggal Keberangkatan : " << setw(20) << left << curr->ticket.tanggal << " |" << endl;
								cout << "| Kota Asal             : " << setw(20) << left << curr->ticket.origin << " |" << endl;
								cout << "| Kota Tujuan           : " << setw(20) << left << curr->ticket.destination << " |" << endl;
								cout << "| Maskapai              : " << setw(20) << left << curr->ticket.flightMaskapai << " |" << endl;
								cout << "| Jadwal Penerbangan    : " << setw(20) << left << curr->ticket.flightSchedule << " |" << endl;
								cout << "| Harga Tiket           : " << setw(20) << left << curr->ticket.flightPrice << " |" << endl;
								cout << "| Nomor Kursi           : " << setw(20) << left << curr->ticket.seatNumber << " |" << endl;
								cout << "================================================" << endl;
								curr = curr->next;
							}
						}
					} else if (choice == 4) {
						// Tampilkan Penerbangan Yang Tersedia
						system("cls");
						jadwal();
					} else if (choice == 5) {
						// Lakukan Pembayaran
						system("cls");
						system("cls");
						makePayment(bookedTickets);
					} else if (choice == 6) {
						// Logout
						system("cls");
						break;
					} else {
						cout << "Pilihan tidak valid." << endl;
					}
				}
			} else {
				cout << "Username atau password salah." << endl;
			}
		} else if (choice == 2) {
			// Register
			string username, password;
			system("cls");
			cout << "Masukkan username: ";
			cin >> username;
			cout << "Masukkan password: ";
			cin >> password;

			registerUser(registeredUsers, username, password);
		} else if (choice == 3) {
			// Keluar
			break;
		} else {
			cout << "Pilihan tidak valid." << endl;
		}
	}

	return 0;
}