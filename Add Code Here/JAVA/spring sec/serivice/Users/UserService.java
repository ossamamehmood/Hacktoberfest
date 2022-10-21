package com.example.informatic_parc.service.Users;

import com.example.informatic_parc.model.Users.Users;
import com.example.informatic_parc.repository.Users.Users_Repository;
import lombok.AllArgsConstructor;
import org.springframework.security.core.userdetails.UserDetails;
import org.springframework.security.core.userdetails.UserDetailsService;
import org.springframework.security.core.userdetails.UsernameNotFoundException;
import org.springframework.security.crypto.bcrypt.BCryptPasswordEncoder;
import org.springframework.stereotype.Service;

import java.util.List;

@Service
@AllArgsConstructor
public class UserService implements UserDetailsService {
    private final Users_Repository repository;

    @Override
    public UserDetails loadUserByUsername(String username) throws UsernameNotFoundException {
        Users user = repository.findUsersByUsername(username);
        return new UserDetailsPrincipal(user);
    }

    public Users addUser(Users user) {
        user.setPassword(new BCryptPasswordEncoder().encode(user.getPassword()));
        return repository.save(user);
    }

    public List<Users> getAll() {
        return repository.findAll();
    }

    public String deleteAll() {
        repository.deleteAll();
        return "All users has been deleted";
    }

    public String deleteUser(Integer id) {
        repository.deleteById(id);
        return "The user with the identity :" + id + ",has been deleted with success ";
    }
}
