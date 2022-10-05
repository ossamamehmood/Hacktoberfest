package com.example.informatic_parc.repository.Users;

import com.example.informatic_parc.model.Users.Roles;
import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.stereotype.Repository;

@Repository
public interface Role_Repository extends JpaRepository<Roles, Integer> {
}
