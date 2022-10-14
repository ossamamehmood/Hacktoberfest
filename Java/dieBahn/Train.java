/**
* Small object oriented program in the form of a train and wagon, based on the concept of pointers 
* A new train has no wagons   
* Wagons can be added or removed from the train using the methods provided 
* Each wagon has a reference to its nextWagon, and can be referred to only from its predecessor 
*/

public class Train {

    public Wagon firstWagon;

    public Train() {
        firstWagon = null;
    }


    /**
     * Attaches a new wagon to the train
     */

    public void attachWagon(Wagon newWagon) {

        if (newWagon == null) { // the wagon must exist
            throw new IllegalArgumentException("Wagon does not exist!");
        } else if (firstWagon == null) { // if the train doesn't yet have a wagon
            firstWagon = newWagon;
        }

        // checks if each wagon has a successor. If not, attach new wagon
        Wagon currentWagon = firstWagon;

        while (currentWagon != null) { // as long as the train has at least one wagon
            if (currentWagon.nextWagon == null) {
                currentWagon.nextWagon = newWagon;
            } else {
                currentWagon = currentWagon.nextWagon; // else, point to next wagon and continue search
            }
        }
    }

    /**
     * Removes a wagon from the train
     */


    public boolean removeWagon(Wagon wagen) {
        if (wagen == null) { // the wagon must exist
            throw new IllegalArgumentException("Wagon does not exist");
        }
        if (firstWagon == null) { // checks if the wagon is part of the train
            throw new IllegalArgumentException("Wagon not found on train");
        }
        Wagon currentWagon = firstWagon;
        Wagon predecessor = null;

        while (currentWagon != null) {

            if (currentWagon == wagen) {
                if (predecessor == null) { // if first wagon
                    firstWagon = firstWagon.nextWagon; // remove wagon and bring next wagon forward
                } else {
                    predecessor.nextWagon = currentWagon.nextWagon;
                }
                return true;
            } else {
                predecessor = currentWagon;
                currentWagon = currentWagon.nextWagon; // continue the search
            }
        }
        return false;
    }
}