import {Link} from 'react-router-dom'
function NavBar({signIn,loggedIn}){
    return(
        <>
        <Link to="/" style={{marginRight:10}}>Home</Link>
        <Link to="/about" style={{marginRight:10}}>About</Link>
        <button onClick={()=>signIn()}>{loggedIn==false?"Sign In" : "Sign Out"}</button>
        </>
    )
}
export default NavBar