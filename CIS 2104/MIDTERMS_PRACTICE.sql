CREATE DATABASE instagram;

USE instagram;

CREATE TABLE users (
    id INTEGER AUTO_INCREMENT PRIMARY KEY,
    username VARCHAR(255) UNIQUE NOT NULL,
    created_at TIMESTAMP DEFAULT NOW()
);
    
CREATE TABLE photos (
    id INTEGER AUTO_INCREMENT PRIMARY KEY,
    image_url VARCHAR(255) NOT NULL,
    user_id INTEGER NOT NULL,
    created_at TIMESTAMP DEFAULT NOW(),
    FOREIGN KEY(user_id) REFERENCES users(id)
);

CREATE TABLE comments (
	id INTEGER AUTO_INCREMENT PRIMARY KEY,
    comment_text VARCHAR(255) NOT NULL,
    user_id INTEGER NOT NULL,
    photo_id INTEGER NOT NULL,
    created_at TIMESTAMP DEFAULT NOW(),
    FOREIGN KEY(user_id) REFERENCES users(id),
    FOREIGN KEY(photo_id) REFERENCES photos(id)
);

CREATE TABLE likes (
	user_id INTEGER NOT NULL,
    photo_id INTEGER NOT NULL,
    created_at TIMESTAMP DEFAULT NOW(),
    FOREIGN KEY(user_id) REFERENCES users(id),
    FOREIGN KEY(photo_id) REFERENCES photos(id),
    PRIMARY KEY(user_id, photo_id)
);

CREATE TABLE follows (
	follower_id INTEGER NOT NULL,
    followee_id INTEGER NOT NULL,
    created_at TIMESTAMP DEFAULT NOW(),
    FOREIGN KEY(follower_id) REFERENCES users(id),
    FOREIGN KEY(followee_id) REFERENCES users(id),
    PRIMARY KEY(follower_id, followee_id)
);

CREATE TABLE tags (
	id INTEGER AUTO_INCREMENT PRIMARY KEY,
    tag_name VARCHAR(255) UNIQUE,
    created_at TIMESTAMP DEFAULT NOW()
);

CREATE TABLE photo_tags (
    photo_id INTEGER NOT NULL,
    tag_id INTEGER NOT NULL,
    FOREIGN KEY(photo_id) REFERENCES photos(id),
    FOREIGN KEY(tag_id) REFERENCES tags(id),
    PRIMARY KEY(photo_id, tag_id)
);

-- FINDING 5 OLDEST USERS

SELECT * FROM users; -- all

SELECT * FROM users ORDER BY created_at LIMIT 5;

-- MOST POPULAR REGISTRATION DATE

SELECT 
    DAYNAME(created_at) AS day,
    COUNT(*) AS total
FROM users 
	GROUP by day
    ORDER BY total DESC;

-- FIND USERS WITH NO POSTS

USE
    instagram;
    
SELECT
    username,
    image_url
FROM
    users
LEFT JOIN photos ON users.id = photos.user_id
WHERE
    photos.id IS NULL;

-- POST WITH MOST LIKES --

SELECT
    username,
    image_url,
    COUNT(*) AS like_count
FROM
    photos
INNER JOIN likes ON likes.photo_id = photos.id
INNER JOIN users ON photos.user_id = users.id
GROUP BY
    photos.image_url
ORDER BY
    like_count
DESC;

-- AVERAGE # OF TIMES A USER POSTS
SELECT (SELECT COUNT(*) FROM photos) / (SELECT COUNT(*) FROM users);

-- NUMBER OF TIMES EACH USER HAS POSTED
SELECT username, COUNT(*) AS times_posted FROM users INNER JOIN photos ON photos.user_id = users.id GROUP BY username;\

-- TOP TAGS USED

SELECT
    tag_name,
    COUNT(*) AS occurences
FROM
    tags
INNER JOIN photo_tags ON photo_tags.tag_id = tags.id
GROUP BY
    tag_name
ORDER BY
    occurences
DESC
    ;

-- FIND BOTS THAT HAVE LIKED EVERY PHOTO
SELECT
    username,
    COUNT(*) AS num_of_liked_posts
FROM
    users
INNER JOIN likes ON users.id = likes.user_id
GROUP BY
    username
HAVING
    num_of_liked_posts =(
SELECT
    COUNT(*)
FROM
    photos
);