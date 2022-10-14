package com.example.informatic_parc.service.Users;

import com.example.informatic_parc.model.Users.Roles;
import com.example.informatic_parc.repository.Users.Role_Repository;
import lombok.AllArgsConstructor;
import org.springframework.stereotype.Service;

@AllArgsConstructor
@Service
public class RoleService {
    private Role_Repository repository;
    public Roles addRole(Roles role){
        return repository.save(role);
    }
    public Roles getAll(){
        return (Roles) repository.findAll();
    }
}
