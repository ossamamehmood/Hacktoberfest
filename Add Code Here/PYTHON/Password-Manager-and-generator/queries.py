import oracledb


class Queries:
    __curs = None
    __conn = None

    def __init__(self):
        # connecting the class with the oracle database
        oracledb.init_oracle_client()
        self.__conn = oracledb.connect(user="prastab", password="mukhopadhyay", host="LAPTOP-2KQAITLT", port=1522,
                                       service_name="orcl")
        self.__curs = self.__conn.cursor()

    def insert(self, acc, dom, psd):
        sql = """insert into password2 (account, domain, password)
             values(:account, :dom, :pswd)"""
        self.__curs.execute(sql, [acc, dom, psd])
        self.__conn.commit()
        print("Password stored")

    def display1(self):
        self.__curs.execute("select * from password2")
        rows = self.__curs.fetchall()
        for row in rows:
            print(row)

    def display2(self, acc):
        self.__curs.execute("select * from password2 where account= :acc", [acc, ])
        rows = self.__curs.fetchall()
        for row in rows:
            print(row)

    def update(self, acc, psd):
        self.__curs.execute("""
                update password2 set password = :pswd
                where account = :acc""", [psd, acc])
        self.__conn.commit()

    def close(self):
        self.__curs.close()




















































