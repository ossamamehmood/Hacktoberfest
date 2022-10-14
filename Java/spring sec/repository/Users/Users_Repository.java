package com.example.informatic_parc.repository.Users;

import com.example.informatic_parc.model.Users.Users;
import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.stereotype.Repository;


@Repository
public interface Users_Repository extends JpaRepository<Users,Integer> {
    Users findUsersByUsername(String username);
}
