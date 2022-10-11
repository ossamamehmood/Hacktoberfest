import random

class Bank:
    def __init__(self):
        self.nama = ""
        self.rekening = 0
        self.pin = 0
        self.saldo = 0

    def buatAkun(self, nama, pin):
        self.nama = nama
        self.rekening = random.randint(11111111, 99999999)
        self.saldo = 50000
        self.pin = pin

        return self.rekening

    def cekRekening(self, rekening):
        return self.rekening == rekening

    def cekPin(self, pin):
        return self.pin == pin

    def cekSaldo(self, rekening):
        if self.cekRekening(rekening):
            return self.saldo

        return False

    def kurangiSaldo(self, rekening, jumlah):
        if self.cekRekening(rekening):
            self.saldo -= jumlah
            return self.saldo

        return 0
    
