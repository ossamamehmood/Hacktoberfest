package com.example.demo;

import com.google.common.hash.Hashing;
import org.apache.commons.validator.routines.UrlValidator;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.data.redis.core.StringRedisTemplate;
import org.springframework.web.bind.annotation.*;

import java.nio.charset.StandardCharsets;

@RequestMapping(value = "/rest/url", method = RequestMethod.GET) // rest endpoint
@RestController // since using spring mvc framework

public class UrlShortenerAlgorithm {

    @Autowired
    StringRedisTemplate redisTemplate;

    @GetMapping("/{id}")
    public String getUrl(@PathVariable String id) { // for getting original url

        String url = redisTemplate.opsForValue().get(id);

        // log for reference
        System.out.println("Url Retrieved : " + url);

        if (url == null) {
            throw new RuntimeException("There is no shorter Url for : " + id);
        }

        return url;
    }

    @PostMapping
    public String create(@RequestBody String url) { // for getting short url

        // validate using pom library
        UrlValidator urlValidator = new UrlValidator(
                new String[]{"http", "https"} // type of urls to shorten, so it won't shorten ftp
        );

        if (urlValidator.isValid(url)) {
            // generate hash based on this url, we will use murmurHash3
            String id = Hashing.murmur3_32().hashString(url, StandardCharsets.UTF_8).toString();

            // also log this id for reference
            System.out.println("Url Id Generated : " + id);

            // populate this id, url in redis cache , {string, string}
            redisTemplate.opsForValue().set(id, url);
            return id;
        }

        throw new RuntimeException("Url Invalid : " + url);
    }
}
