import styles from './FirstPage.module.css'
import {Button} from 'antd'


function FirstPage({loggedInState}){
    return(
        <>
        
        <h1 className={styles["header-Color"]}>First Page</h1>
        </>
    ) 
}

export default FirstPage