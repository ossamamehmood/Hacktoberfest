import matplotlib.pyplot as plt

aVvals,aCvals,pRvals,uIvals, CIAvals = [0.85,0.62,0.55,0.2],[0.77,0.44],[[0.85,0.85],[0.62,0.68],[0.27,0.5]],[0.85,0.62], [0, 0.22, 0.56]

print("Scope (SC)\n1.Unchanged(UC)\t2.Changed(C)\n")
sc = int(input("Enter Scope (1-2) :: "))

print("\nAttack Vector (AV)\n1.Network(N)\t2.Adjacent(A)\t3.Local(L)\t4.Physical(P)\n")
attackVector = aVvals[int(input("Enter Attack Vector (1-4) :: "))-1]

print("\nAttack Complexity (AC)\n1.Low(L)\t2.High(H)\n")
attackComplexity = aCvals[int(input("Enter Attack Complexity (1-2) :: "))-1]

print("\nPrivileges Required (PR)\n1.None(N)\t2.Low(L)\t3.High(H)\n")
privilegesRequired = pRvals[int(input("Enter Privileges Required (1-3) :: "))-1][sc-1]

print("\nUser Interaction (UI)\n1.None(N)\t2.Required(R)\n")
userInteraction = uIvals[int(input("Enter User Interaction (1-2) :: "))-1]

print("\nConfidentiality (C)\n1.None(N)\t2.Low(L)\t3.High(H)\n")
confidentiality = CIAvals[int(input("Enter Confidentiality (1-3) :: "))-1]

print("\nIntegrity (I)\n1.None(N)\t2.Low(L)\t3.High(H)\n")
integrity = CIAvals[int(input("Enter Integrity (1-3) :: "))-1]

print("\nAvailability (A)\n1.None(N)\t2.Low(L)\t3.High(H)\n")
availability = CIAvals[int(input("Enter Availability (1-3) :: "))-1]

ISSval = 1-((1-confidentiality)*(1-integrity)*(1-availability))
impactVal = round(6.42*ISSval) if sc==1 else round((7.52*(ISSval-0.029)) - (3.25*pow((ISSval-0.02),15)))
exploitVal = round(8.22 * attackVector * attackComplexity * privilegesRequired * userInteraction)
baseVal = 0
if impactVal == 0 :
    baseVal = 0
elif sc==1:
    baseVal = round(min((impactVal + exploitVal),10))
else:
    baseVal = round(min((1.08*(impactVal + exploitVal)),10))

plt.bar(["Base","Impact","Exploitability"],[baseVal,impactVal,exploitVal])
plt.xlabel("Categories")
plt.ylabel("CVSS Score")
plt.text(0,baseVal,baseVal,ha='center')
plt.text(1,impactVal,impactVal,ha='center')
plt.text(2,exploitVal,exploitVal,ha='center')
plt.show()
