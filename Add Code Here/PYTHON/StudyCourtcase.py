print('''Type in a number to get a summary of each Court Case!
50. Marbury v. Madison 1803
51. McCulloch v. MD 1819
52. Gibbons v. Ogden 1824
53. Dred Scott v. Sanford 1857
54. Slaughterhouse Cases 1873
55. Plessy v. Ferguson 1896
56. Lochner v. NY 1905
57. Schenck v. US 1919
58. Korematsu v. US 1944
59. Brown v. Board of Education 1954
60. Mapp v. OH 1961
61. Engel v. Vitale 1962
62. Baker v. Carr 1962
63. Gideon v. Wainwright 1963
64. Escobedo v. Illinois 1964
65. Griswold v. CT 1965
66. Miranda v. AZ 1966
67. Tinker v. Des Moines 1969
68. New York Times Company v. US 1971
69. Swann v. Charlotte-Mecklenburg BOE 1971
70. Lemon v. Kurtzman 1971
71. Roe v. Wade 1972
72. Wisconsin v. Yoder 1972
73. Miller v. CA 1973
74. US v. Nixon 1974
75. Buckley v. Valeo 1976
76. Regents of University of California v. Bakke 1978
77. US v. Lopez 1995
78. Reno v. ACLU 1997
79. Bush v. Gore 2000
80. Lawrence v. TX 2003
81. Citizens United v. FEC 2010
82. McCutcheon v FEC 2014''')
for i in range (100):
    A = input()
    if A == '50':
        print('Marbury v. Madison 1803: Established Judicial Review.')
    elif A == '51':
        print('McCulloch v. MD 1819: States cannot tax Congress owned banks(unenumerated power).')
    elif A == '52':
        print('Gibbons v. Ogden 1824: States have less power than Federal (Supremacy clause).')
    elif A == '53':
        print('Dred Scott v. Sanford 1857: Slaves are properties and cannot be set free even if they move to a free state.')
    elif A == '54':
        print('Slaughterhouse Cases 1873: Privileges and Immunities Clause of the 14th Amendment only protect us from losing National citizenship rights, not protect one state from another.')
    elif A == '55':
        print('Plessy v. Ferguson 1896: Established "separate but equal".')
    elif A == '56':
        print('Lochner v. NY 1905: States cannot determine the hours of labor for an individual (due process clause; 14th Amendment).')
    elif A == '57':
        print('Schenck v. US 1919: free speech can be limited during war times.')
    elif A == '58':
        print('Korematsu v. US 1944: compulsory exclusion is permitted during war times.')
    elif A == '59':
        print('Brown v. Board of Education 1954: Repealed "Plessy v. Ferguson; we now have integrated school.')
    elif A == '60':
        print('Mapp v. OH 1961: Exclusionary Act - information obtained from illegal searches and seizure (4th Amendment) cannot be used as evidence in court.')
    elif A == '61':
        print('Engel v. Vitale 1962: Government and Religion is separated (religious prayers).')
    elif A == '62':
        print('Baker v. Carr 1962: States must redistrict every 10 years; established "Judicial Question" (whether a case merited judicial evaluation).')
    elif A == '63':
        print("Gideon v. Wainwright 1963: 6th Amendment; we are given an attorney if we don't have one.")
    elif A == '64':
        print('Escobedo v. Illinois 1964: 5th Amendment right against self-incrimination.')
    elif A == '65':
        print('Griswold v. CT 1965: Right to maritial privacy is implied by the 1st, 3rd, 4th, and 9th Amendment.')
    elif A == '66':
        print('Miranda v. AZ 1966: Miranda rights (Police must inform you of your right to remain silent and have a voluntary waiver to interrogate).')
    elif A == '67':
        print('Tinker v. Des Moines 1969: Students have freedom of speech.')
    elif A == '68':
        print('New York Times Company v. US 1971: Government cannot place "prior restraint" on the press if it does not cause an inevitable, direct, and immediate danger.')
    elif A == '69':
        print('Swann v. Charlotte-Mecklenburg BOE 1971: Extended Brown v. BOE by imposing a set of guidelines to desegregate schools.')        
    elif A == '70':
        print('Lemon v. Kurtzman 1971: Established "Lemon Test" to separate government and religion(type 70.1 for more information on "Lemon Test").')
    elif A == '71':
        print('Roe v. Wade 1972: Extended "Griswold v. Connecticut; abortion falls under right to privacy and is allowed.')
    elif A == '72':
        print('Wisconsin v. Yoder 1972: Freedom of religion in 1st Amendment outweight State laws.')
    elif A == '73':
        print('Miller v. CA 1973: Obscenity is unprotected speech but the definition of "obscene material" is lessened.')
    elif A == '74':
        print('US v. Nixon 1974: Executive branch and the goverment can only hide military and diplomatic information.')
    elif A == '75':
        print('Buckley v. Valeo 1976: limit individual contributions to $1,000; no limit of self-funding.')
    elif A == '76':
        print('Regents of University of California v. Bakke 1978: Only use quotas (required to have X number of minorities) in affirmative action when it is absolutely neccessary.')
    elif A == '77':
        print('US v. Lopez 1995: The 2nd Amendment let you carry firearms.')
    elif A == '78':
        print('Reno v. ACLU 1997: The Communications Decency Act of 1996 was unconstitutional because it was broad and vague and depicting was is adult materials and who is an adult.')
    elif A == '79':
        print("Bush v. Gore 2000: Standardless manual recounts violate the 14th Amendment's Equal Protection Clause.")
    elif A == '80':
        print('Lawrence v. TX 2003: Gay sexual intercourses is now legal because of right to privacy and liberty.')
    elif A == '81':
        print('Citizens United v. FEC 2010: The 1st Amendment protects right to free speech.')
    elif A == '82':
        print('McCutcheon v FEC 2014: aggregated limits is unconstitutional.')
    elif A == '70.1':
        print('''Lemon Test:
        1) Have a secular(non-religious) legislative purpose
        2. Does not advance or inhibit religion
        3. Not result in "excessive entanglement" with religion''')
        
