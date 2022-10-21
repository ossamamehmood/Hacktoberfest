package com.example.informatic_parc.controller.Users;

import com.example.informatic_parc.model.Users.Users;
import com.example.informatic_parc.service.Users.UserService;
import lombok.AllArgsConstructor;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;

import java.util.List;

@RestController
@AllArgsConstructor
public class Users_Controller {
    @Autowired
    UserService service;
    @PostMapping("/users")
    public Users addUser( @RequestBody Users user){
        return service.addUser(user);
    }
    @GetMapping("/users")
    public List<Users> getAll(){
        return service.getAll();
    }
    @DeleteMapping("/delete/users")
    public String deleteAll(){
        return service.deleteAll();
    }
    @DeleteMapping("/delete/users/{id}")
    public String delete( @PathVariable Integer id){
        return service.deleteUser(id);
    }
}
